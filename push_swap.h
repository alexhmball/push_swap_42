#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_listy
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_listy;

void print_error(int flag);

#endif