/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 21:25:29 by vinvimo           #+#    #+#             */
/*   Updated: 2017/10/16 23:12:25 by vinvimo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define ERRORCHECK(x) if (!x) return (-1)
# define BUFF_SIZE 100

typedef struct		s_struct
{
	int				fd;
	struct s_box	*list;
	struct s_box	**p;
	int				add;
	long			ants;
	int				sig;
	int				sig_start;
	int				sig_end;
	int				num;
	int				index;
	int				index_2;
	char			**tab;
}					t_struct;

typedef struct		s_box
{
	char			*name;
	int				num;
	int				ants;
	long			coorx;
	long			coory;
	int				sig_start;
	int				sig_end;
	int				step;
	struct s_box	**nod;
	struct s_box	*next;
}					t_box;

typedef struct		s_gnl
{
	char			*content;
	int				fd;
	struct s_gnl	*next;
}					t_gnl;

int					main(void);
void				initialize(t_struct *t, t_box *list);
int					get_next_line(const int fd, char **line);
int					valid_line(char *line, int ret);
int					*ft_intnew(size_t size);
int					lemin(t_struct *t, char *line, int ret);
int					get_data(t_struct *t, char *line, int i);
int					go(t_struct *t, t_box *tmp);
int					box(t_struct *t, t_box *tmp, char *line, int i);
void				fill(t_struct *t);
int					check_new_box(t_struct *t, t_box *tmp, int i, int j);
int					sweep(t_struct *t, t_box *tmp);
int					tube(t_struct *t, char *line, int i);
void				connectors(t_struct *t, t_box *tmp);
int					match(t_struct *t, t_box *tmp1, t_box *tmp2);
void				command(t_struct *t, t_box *tmp);
int					explore(t_struct *t, t_box *list, int a, int b);
int					route(t_struct *t, t_box *list, int a, int b);
void				trace(t_box *list, int tmp, int *b, int *ants);
void				ft_strdel_2d(char **as);
int					del_ret_2d(char **tab, int sig);
void				clean(t_struct *t, t_box *tmp);

#endif
