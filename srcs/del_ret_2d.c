/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_ret_2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 23:13:23 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/16 23:13:26 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		del_ret_2d(char **tab, int sig)
{
	ft_strdel_2d(tab);
	return (sig);
}
