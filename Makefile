# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aball <aball@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 01:47:33 by aball             #+#    #+#              #
#    Updated: 2022/06/21 01:47:34 by aball            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap_utils.c main.c

$(NAME): all

all: libft ${SRCS}
	gcc -g -Wall -Wextra -Werror libft/libft.a ${SRCS} -o ${NAME}

libft:
	make -C libft
	make bonus -C libft

clean:
	rm -fr $(NAME)
	make clean -C libft

.PHONY: all libft