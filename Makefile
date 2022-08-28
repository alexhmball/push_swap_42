# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 01:47:33 by aball             #+#    #+#              #
#    Updated: 2022/08/28 23:29:26 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FILES = push_swap_utils.c main.c sorting.c push.c swap.c rotate.c algo.c check.c \
	small_sort.c size.c find.c rotate_two.c error.c big_sort.c free.c

SRCS = $(addprefix srcs/, ${FILES})

$(NAME): all

all: libft ${SRCS}
	gcc -Wall -Wextra -Werror ${SRCS} libft/libft.a -o ${NAME}

libft:
	make -C libft

clean:
	make clean -C libft

fclean:
	rm -fr $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all libft clean fclean