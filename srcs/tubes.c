/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tubes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 21:25:55 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/16 22:48:10 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		match(t_struct *t, t_box *tmp1, t_box *tmp2)
{
	int		c;

	while (tmp1 && ft_strcmp(tmp1->name, t->tab[0]))
		tmp1 = tmp1->next;
	while (tmp2 && ft_strcmp(tmp2->name, t->tab[1]))
		tmp2 = tmp2->next;
	if (tmp1 == NULL || tmp2 == NULL)
	{
		ft_strdel_2d(t->tab);
		return (1);
	}
	c = 0;
	while (tmp1->nod[c] && tmp1->nod[c] != tmp2)
		c++;
	tmp1->nod[c] = tmp2;
	tmp1->nod[c + 1] = NULL;
	c = 0;
	while (tmp2->nod[c] && tmp2->nod[c] != tmp1)
		c++;
	tmp2->nod[c] = tmp1;
	tmp2->nod[c + 1] = NULL;
	ft_strdel_2d(t->tab);
	return (1);
}

int		tube(t_struct *t, char *line, int i)
{
	t->tab = ft_strsplit(line, '-');
	i = 0;
	while (t->tab[i])
		i++;
	if (i != 2)
	{
		ft_strdel_2d(t->tab);
		return (0);
	}
	return (match(t, t->list, t->list));
}

void	connectors(t_struct *t, t_box *tmp)
{
	int	i;

	t->sig = 1;
	while (tmp)
	{
		if (!(tmp->nod = (t_box**)malloc(sizeof(t_box*) * (t->num + 1))))
			exit(0);
		i = 0;
		while (i < t->num + 1)
			tmp->nod[i++] = NULL;
		tmp = tmp->next;
	}
	if (!(t->p = (t_box**)malloc(sizeof(t_box*) * (t->num * t->num))))
		exit(0);
	i = 0;
	while (i < t->num * t->num)
		t->p[i++] = NULL;
	t->index = 0;
	t->index_2 = 0;
}
