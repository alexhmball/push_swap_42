# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 01:47:33 by aball             #+#    #+#              #
#    Updated: 2022/07/01 23:10:51 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap_utils.c main.c sorting.c push.c swap.c rotate.c

$(NAME): all

all: libft ${SRCS}
	gcc -g -Wall -Wextra -Werror libft/libft.a ${SRCS}  -o ${NAME}

libft:
	make -C libft
	make bonus -C libft

clean:
	make clean -C libft

fclean:
	rm -fr $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all libft