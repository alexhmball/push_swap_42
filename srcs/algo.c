/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:35:21 by aball             #+#    #+#             */
/*   Updated: 2022/09/07 16:18:46 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse(t_listy **b, t_listy *temp_b)
{
	while (is_largest(b, temp_b) == 0)
	{
		rev_rotate_b(b);
		temp_b = *b;
	}
}

static void	rotate_down(t_listy **b, t_listy *temp_b)
{
	while (is_largest(b, temp_b) == 0)
	{
		rotate_b(b);
		temp_b = *b;
	}
}

void	bring_to_top(t_listy **a, int min, int size)
{
	t_listy	*temp_a;

	temp_a = *a;
	while (temp_a->content != min)
	{
		// printf("%d   %d\n", min, temp_a->content);
		if (find_node(a, min) > size / 2)
			rev_rotate_a(a);
		else
			rotate_a(a);
		temp_a = *a;
	}
}

void	sort_algo(t_listy **a, t_listy **b)
{
	t_listy	*temp_b;

	while (lst_size(*b) != 0)
	{
		temp_b = *b;
		if (is_largest(b, temp_b))
			push_a(a, b);
		else if (largest_position(b) == 1)
			swap_b(b);
		else if (largest_position(b) >= lst_size(*b) / 2)
			rotate_reverse(b, temp_b);
		else if (largest_position(b) < lst_size(*b) / 2)
			rotate_down(b, temp_b);
	}
}
