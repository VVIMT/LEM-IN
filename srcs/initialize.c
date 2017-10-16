/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 21:25:19 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/16 22:23:36 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	initialize(t_struct *t, t_box *list)
{
	list->next = NULL;
	list->sig_start = 0;
	list->sig_end = 0;
	list->step = -1;
	list->ants = 0;
	t->sig = 0;
	t->sig_start = 0;
	t->sig_end = 0;
	t->num = 1;
	t->add = 0;
	t->list = list;
}
