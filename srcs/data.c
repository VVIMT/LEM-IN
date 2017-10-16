/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 21:19:54 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/16 22:23:06 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		get_data(t_struct *t, char *line, int i)
{
	if (ft_strncmp(line, "##", 2) == 0)
	{
		i = 2;
		if (ft_strncmp(line + i, "start", 5) == 0)
			t->sig_start = 1;
		else if (ft_strncmp(line + i, "end", 3) == 0)
			t->sig_end = 1;
	}
	else if ((line[0] == 'L' || line[0] == '#') && line[1] != '#')
		return (1);
	else
	{
		if (!box(t, t->list, line, 0))
		{
			if (t->sig == 0)
				connectors(t, t->list);
			if (!tube(t, line, -1))
				return (0);
		}
		else if (box(t, t->list, line, 0) == -1)
			return (-1);
		t->sig_start = 0;
		t->sig_end = 0;
	}
	return (1);
}

int		go(t_struct *t, t_box *tmp)
{
	while (tmp && tmp->sig_start != 1)
		tmp = tmp->next;
	if (tmp == NULL || t->ants <= 0 || t->num < 2
	|| (tmp->sig_start == 1 && tmp->sig_end == 1))
		return (0);
	tmp->ants = t->ants;
	if (!explore(t, tmp, -1, 0))
		return (0);
	return (1);
}

int		lemin(t_struct *t, char *line, int ret)
{
	get_next_line(t->fd, &line);
	if (!valid_line(line, -1))
		return (0);
	t->ants = ft_atoi(line);
	ft_putendl(line);
	ft_strdel(&line);
	while (get_next_line(t->fd, &line))
	{
		ret = get_data(t, line, 0);
		ret ? ft_putendl(line) : 0;
		ft_strdel(&line);
		if (!ret || ret == -1)
			break ;
	}
	ft_putchar('\n');
	if (ret == -1)
		return (0);
	if (!go(t, t->list))
		return (0);
	clean(t, t->list);
	return (1);
}

int		valid_line(char *line, int ret)
{
	int	sig;

	sig = 1;
	if (*line == 0)
		sig = 0;
	while (line[++ret])
		if (!ft_isdigit(line[ret]))
			sig = 0;
	return (sig);
}

void	clean(t_struct *t, t_box *tmp)
{
	while (tmp)
	{
		ft_strdel(&(tmp->name));
		if (tmp->nod)
			free(tmp->nod);
		t->list = tmp;
		tmp = tmp->next;
		if (t->list->next != NULL)
			free(t->list);
	}
	t->list = NULL;
}
