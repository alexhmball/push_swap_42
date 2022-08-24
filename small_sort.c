/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:18:57 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 22:42:37 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	}
}

void	sort_five(t_listy **a, t_listy **b)
{
	t_listy	*temp_a;

	temp_a = *a;
	if (is_smallest(a, temp_a) == 0 && is_smallest(a, temp_a->next) == 0
		&& is_smallest(a, temp_a->next->next) == 0)
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
	}
}
