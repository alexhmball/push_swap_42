/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:18:57 by aball             #+#    #+#             */
/*   Updated: 2022/08/04 20:21:03 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smallest(t_listy **a, t_listy *node)
{
	t_listy	*current;

	current	= *a;
	while (current)
	{
		if (current->index < node->index)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_listy **a)
{
	t_listy	*temp_a;

	temp_a = *a;
	if (is_smallest(a, lst_last(*a)))
	{
		if (temp_a->index > temp_a->next->index)
			swap_a(a);
		rev_rotate_a(a);
	}
	if (is_smallest(a, temp_a->next))
	{
		if (temp_a->index < lst_last(*a)->index)
			swap_a(a);
		else
		{
			rev_rotate_a(a);
			rev_rotate_a(a);
		}
	}
	if (is_smallest(a, temp_a) && is_sorted_a(a) == 0)
	{
		rotate_a(a);
		swap_a(a);
		rev_rotate_a(a);
	}
}

void	sort_four(t_listy **a, t_listy **b)
{
	t_listy	*temp_a;
	int		i;

	temp_a = *a;
	i = 0;
	while (temp_a->index != 0)
	{
		i++;
		temp_a = temp_a->next;
	}
	temp_a = *a;
	if (i > 1)
	{
		while (i)
		{
			rev_rotate_a(a);
			i--;
		}
	}
	else if (temp_a->next->index == 0)
		rotate_a(a);
	push_b(a, b);
	temp_a = *a;
	sort_three(a);
	if (is_sorted_b(b) == 0)
		swap_b(b);
	push_a(a, b);
}



// void	sort_five(t_listy **a, t_listy **b)
// {
// }