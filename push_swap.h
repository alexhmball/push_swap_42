/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:55 by aball             #+#    #+#             */
/*   Updated: 2022/08/28 17:00:12 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_listy
{
	int				content;
	struct s_listy	*next;
}				t_listy;

void	print_error(int flag);
t_listy	*new_lst(int content);
void	lst_add_front(t_listy **lst, t_listy *new);
void	lst_add_back(t_listy **lst, t_listy *node);
void	push_b(t_listy **a_head, t_listy **b_head);
void	push_a(t_listy **a_head, t_listy **b_head);
void	sorting(t_listy **a, int size, int median, int *numbers);
int		lst_size(t_listy *lst);
void	delone(t_listy *lst, void (*del)(void *));
void	swap(t_listy **head);
int		is_sorted_a(t_listy **a_head);
int		is_sorted_b(t_listy **b_head);
t_listy	*lst_last(t_listy **lst);
void	sort_three(t_listy **a);
void	swap_b(t_listy **head);
void	swap_a(t_listy **head);
void	rotate_b(t_listy **head);
void	rotate_a(t_listy **head);
void	rev_rotate_b(t_listy **head);
void	rev_rotate_a(t_listy **head);
void	sort_four(t_listy **a, t_listy **b);
void	sort_five(t_listy **a, t_listy **b);
void	swap_a_b(t_listy **a, t_listy **b);
int		find_median(int *nums, int ac);
void	rev_rotate(t_listy **head);
void	rev_rotate_ab(t_listy **a, t_listy **b);
void	rotate_ab(t_listy **a, t_listy **b);
void	rotate(t_listy **head);
void	sort_algo(t_listy **a, t_listy **b);
int		is_smallest(t_listy **a, t_listy *node);
int		is_largest(t_listy **head, t_listy *node);
int		largest_position(t_listy **head);
int		smallest_position(t_listy **head);
int		find_nums_left(t_listy **a, int median);
int		find_upper_half(t_listy **a, int median);
char	*error_handler(int ac, char **av, char *nums);
int		*check_duplicates(char **nums);
void	check_and_error(int *numbers);
int		big_sort(t_listy **a, t_listy **b, int *nums, int size);
int		split_list_lower(t_listy **a, t_listy **b, int median);
void	sort_algo_push_small(t_listy **a, t_listy **b);

#endif