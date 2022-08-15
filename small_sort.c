/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:18:57 by aball             #+#    #+#             */
/*   Updated: 2022/08/06 22:12:39 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_smallest(t_listy **a, t_listy *node)
{
	t_listy	*current;

	current	= *a;
	while (current)
	{
		if (current->content < node->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_listy **a)
{
	t_listy	*temp_a;

	temp_a = *a;
	if (is_smallest(a, lst_last(a)))
	{
		if (temp_a->content > temp_a->next->content)
			swap_a(a);
		rev_rotate_a(a);
	}
	if (is_smallest(a, temp_a->next))
	{
		if (temp_a->content < lst_last(a)->content)
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

	temp_a = *a;
	if (is_smallest(a, temp_a) == 0 && is_smallest(a, temp_a->next) == 0)
	{
		while (is_smallest(a, temp_a) == 0)
		{
			rev_rotate_a(a);
			temp_a = *a;
		}
	}
	else if (is_smallest(a, temp_a->next))
		rotate_a(a);
	if (is_sorted_a(a) == 0)
	{
		push_b(a, b);
		temp_a = *a;
		if (is_sorted_b(b) == 0)
			swap_b(b);
		sort_three(a);
		// push_a(a, b);
	}
}

void	sort_five(t_listy **a, t_listy **b)
{
	t_listy	*temp_a;

	temp_a = *a;
	if (is_smallest(a, temp_a) == 0 && is_smallest(a, temp_a->next) == 0 && is_smallest(a, temp_a->next->next) == 0)
	{
		while (is_smallest(a, temp_a) == 0)
		{
			rev_rotate_a(a);
			temp_a = *a;
		}
	}
	else
	{
		while (is_smallest(a, temp_a) == 0)
		{
			rotate_a(a);
			temp_a = *a;
		}
	}
	if (is_sorted_a(a) == 0)
	{
		push_b(a, b);
		sort_four(a, b);
		// push_a(a, b);
	}
}