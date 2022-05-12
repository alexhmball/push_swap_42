NAME = push_swap

SRCS = main.c

all: libft ${SRCS}
	gcc -g -Wall -Wextra -Werror main.c libft/libft.a -o ${NAME}

libft:
	make bonus -C libft

.PHONY: all libft