/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:55 by aball             #+#    #+#             */
/*   Updated: 2022/07/03 20:55:30 by aball            ###   ########.fr       */
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
void	push_b(t_listy **a_head, t_listy **b_head);
void	push_a(t_listy **a_head, t_listy **b_head);
void	sorting(t_listy *a, int size);
int		lst_size(t_listy *lst);
void	delone(t_listy *lst, void (*del)(void *));
void	swap(t_listy **head);
void	rotate(t_listy **head);
void	rev_rotate(t_listy **head);
int		*pre_sort(int *nums, int ac);
int		is_sorted_a(t_listy **a_head);
int		is_sorted_b(t_listy **b_head);
void	sort_algo(t_listy **a_head, t_listy **b_head);
t_listy	*lst_last(t_listy *lst);
void	sort_three(t_listy **a);

#endif