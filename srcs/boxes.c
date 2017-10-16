/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 21:19:42 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/16 23:13:07 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		sweep(t_struct *t, t_box *tmp)
{
	while (tmp)
	{
		if (ft_strcmp(t->tab[0], tmp->name) == 0)
		{
			if (t->sig_start == 1 || t->sig_end == 1)
				command(t, tmp);
			tmp->coorx = ft_atoi(t->tab[1]);
			tmp->coory = ft_atoi(t->tab[2]);
			t->add = 0;
			return (0);
		}
		else if (tmp->coorx == ft_atoi(t->tab[1])
				&& tmp->coory == ft_atoi(t->tab[2]))
		{
			if (t->sig_start == 1 || t->sig_end == 1)
				command(t, tmp);
			tmp->name = ft_strdup(t->tab[0]);
			t->add = 0;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int		check_new_box(t_struct *t, t_box *tmp, int i, int j)
{
	i = -1;
	while (t->tab[++i])
	{
		if (t->tab[0][0] == 0 || t->tab[0][0] == '\n')
			return (-1);
		if (i == 1)
		{
			j = -1;
			while (t->tab[1][++j])
				if (t->tab[1][j] && !ft_isdigit(t->tab[1][j]))
					return (-1);
		}
		else if (i == 2)
		{
			j = -1;
			while (t->tab[2][++j])
				if (t->tab[2][j] && !ft_isdigit(t->tab[2][j]))
					return (-1);
		}
	}
	return (sweep(t, tmp));
}

void	command(t_struct *t, t_box *tmp)
{
	t_box	*tmp_2;

	tmp_2 = t->list;
	while (tmp_2)
	{
		if (t->sig_start == 1 && tmp_2)
			tmp_2->sig_start = 0;
		if (t->sig_end == 1 && tmp_2)
			tmp_2->sig_end = 0;
		tmp_2 = tmp_2->next;
	}
	tmp->sig_start = t->sig_start;
	tmp->sig_end = t->sig_end;
}

void	fill(t_struct *t)
{
	t->list->num = t->num++;
	t->list->name = ft_strdup(t->tab[0]);
	t->list->coorx = ft_atoi(t->tab[1]);
	t->list->coory = ft_atoi(t->tab[2]);
	t->list->sig_start = t->sig_start;
	t->list->sig_end = t->sig_end;
	t->list->step = -1;
	t->list->ants = 0;
	command(t, t->list);
}

int		box(t_struct *t, t_box *tmp, char *line, int i)
{
	int	ret;
	int	sig;

	sig = 1;
	t->tab = ft_strsplit(line, ' ');
	while (t->tab[i])
		i++;
	if (i != 3)
		return (del_ret_2d(t->tab, 0));
	ret = check_new_box(t, t->list, 0, 0);
	if (ret == 1 && t->add == 1)
	{
		if (!(tmp = (t_box*)malloc(sizeof(t_box))))
			exit(0);
		tmp->next = t->list;
		t->list = tmp;
	}
	else if (ret == -1)
		return (del_ret_2d(t->tab, -1));
	if (ret == 1)
		fill(t);
	t->add = 1;
	return (del_ret_2d(t->tab, 1));
}
