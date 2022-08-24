/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:35:21 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 22:26:56 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		else if (largest_position(b) > lst_size(*b) / 2)
		{
			while (is_largest(b, temp_b) == 0)
			{
				rev_rotate_b(b);
				temp_b = *b;
			}
		}
		else if (largest_position(b) < lst_size(*b) / 2)
		{
			while (is_largest(b, temp_b) == 0)
			{
				rotate_b(b);
				temp_b = *b;
			}
		}
		else
			rotate_b(b);
	}
}