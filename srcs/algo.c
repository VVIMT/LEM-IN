/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 21:19:27 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/16 22:22:38 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	trace(t_box *list, int tmp, int *b, int *ants)
{
	while (list->nod[*b] && list->nod[*b]->step != tmp)
		(*b)++;
	if (list->nod[*b] && list->nod[*b]->ants > 0)
	{
		list->nod[*b]->ants--;
		list->ants++;
		ft_putchar('L');
		ft_putnbr(*ants);
		ft_putchar('-');
		ft_putstr(list->name);
		if (list->nod[*b]->sig_start == 0)
			ft_putchar(' ');
		(*ants)++;
	}
}

int		route(t_struct *t, t_box *list, int a, int b)
{
	t_box	*end;
	int		tmp;
	int		ants;

	while (list->sig_end != 1)
		list = list->next;
	end = list;
	while (end->ants < t->ants)
	{
		list = end;
		tmp = a;
		if (list == NULL)
			return (0);
		ants = 1 + end->ants;
		while (list)
		{
			b = 0;
			trace(list, tmp, &b, &ants);
			list = list->nod[b];
			tmp--;
		}
		ft_putstr("\n");
	}
	return (1);
}

int		explore(t_struct *t, t_box *list, int a, int b)
{
	if (t->sig == 0)
		return (0);
	t->p[0] = list;
	t->p[0]->step = 0;
	while (++a <= t->num + 1)
	{
		while (t->p[t->index] && t->p[t->index]->step == a)
		{
			b = -1;
			while (t->p[t->index]->nod[++b])
			{
				if (t->p[t->index]->nod[b]->step == -1)
				{
					while (t->p[t->index_2])
						t->index_2++;
					t->p[t->index_2] = t->p[t->index]->nod[b];
					t->p[t->index]->nod[b]->step = a + 1;
				}
				if (t->p[t->index]->nod[b]->sig_end == 1)
					return (route(t, t->list, a, 0));
			}
			t->index++;
		}
	}
	return (0);
}
