/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:55 by aball             #+#    #+#             */
/*   Updated: 2022/06/24 18:30:48 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_listy
{
	int				content;
	int				index;
	struct s_listy	*next;
}				t_listy;

void	print_error(int flag);
t_listy	*new_lst(int content, int index);
void	lst_add_front(t_listy **lst, t_listy *new);
void	lst_add_back(t_listy **lst, t_listy *node);
t_listy	**push_b(t_listy **a_head, t_listy **b_head, t_listy *node);
void	sorting(t_listy *a);
int	lst_size(t_listy *lst);

#endif