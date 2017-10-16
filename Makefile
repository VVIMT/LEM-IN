#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vinvimo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/16 22:32:52 by vinvimo           #+#    #+#              #
#    Updated: 2017/10/16 23:14:19 by vinvimo          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=lem-in

CC=gcc

CFLAGS=-Wall -Wextra -Werror

HDDIRS=-I includes/lemin.h

SRCS=srcs/main.c srcs/initialize.c srcs/get_next_line.c srcs/data.c \
srcs/boxes.c srcs/tubes.c srcs/algo.c srcs/ft_strdel_2d.c srcs/del_ret_2d.c

OBJ=$(SRCS:.c=.o)

$(NAME): includes/lemin.h
	@make -C libft/
	$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME) $(HDDIRS)

all: $(NAME)

clean:
	@make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) a.out

re: fclean all

.PHONY: clean
