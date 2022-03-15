# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 23:01:13 by adbaich           #+#    #+#              #
#    Updated: 2022/03/15 09:58:10 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
	ft_lstnew.c \
	push_swap.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_split.c \
	create_lst.c \
	duplicate.c \
	instructions1.c \
	instructions2.c \
	instructions3.c \
	small_sort.c \
	fill_index.c \
	lst_size.c \
	is_sorted.c \
	is_indexed.c \

SRC_BN = checker_bonus.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_split.c \
		ft_atoi.c \
		ft_lstnew.c \
		create_lst.c \

NAME = push_swap

BONUSX = checker

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}:
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

{BONUSX}:
	${CC} ${CFLAGS} {SRC_BN} -o {BONUSX}

bonus: ${BONUSX}

clean:
	${RM} ${NAME}

fclean: clean
	${RM} ${BONUS}

re: fclean all
