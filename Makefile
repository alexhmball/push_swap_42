# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 01:47:33 by aball             #+#    #+#              #
#    Updated: 2022/09/05 18:56:06 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES = push_swap_utils.c main.c sorting.c push.c swap.c rotate.c algo.c check.c \
	small_sort.c size.c find.c rotate_two.c error.c big_sort.c free.c

SRCS = $(addprefix srcs/, ${FILES})

OBJS = ${SRCS:c=o}

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

all: libft $(NAME)

$(NAME): ${OBJS}
	$(CC) $^ libft/libft.a -o $@

%.o: %.c
		${CC} ${FLAGS} -c $< -o ${<:c=o}

libft:
	make -C libft

clean:
	make clean -C libft
	rm -fr ${OBJS}

fclean: clean
	rm -fr $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all libft clean fclean