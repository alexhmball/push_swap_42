/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:14:50 by aball             #+#    #+#             */
/*   Updated: 2022/08/27 21:17:15 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_reverse_small(t_listy **b, t_listy *temp_b)
{
	while (is_smallest(b, temp_b) == 0)
	{
		rev_rotate_b(b);
		temp_b = *b;
	}
}

static void	rotate_down_small(t_listy **b, t_listy *temp_b)
{
	while (is_smallest(b, temp_b) == 0)
	{
		rotate_b(b);
		temp_b = *b;
	}
}

void	sort_algo_push_small(t_listy **a, t_listy **b)
{
	t_listy	*temp_b;

	while (lst_size(*b) != 0)
	{
		temp_b = *b;
		if (is_smallest(b, temp_b))
			push_a(a, b);
		else if (smallest_position(b) == 1)
			swap_b(b);
		else if (smallest_position(b) >= lst_size(*b) / 2)
			rotate_reverse_small(b, temp_b);
		else if (smallest_position(b) <= lst_size(*b) / 2)
			rotate_down_small(b, temp_b);
	}
}