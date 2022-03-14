# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbaich <adbaich@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/19 23:01:13 by adbaich           #+#    #+#              #
#    Updated: 2022/03/13 04:00:29 by adbaich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c \
	ft_lstnew.c \
	push_swap.c \
	ft_lstadd_back.c \
	ft_lstadd_front.c \
	ft_split.c \

NAME = push_swap

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${SRC}
	${CC} ${CFLAGS} ${SRC} -o ${NAME}

clean:
	${RM} ${NAME}

fclean: clean

re: fclean all
