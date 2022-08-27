/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:28:45 by aball             #+#    #+#             */
/*   Updated: 2022/08/27 22:16:44 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_nums(t_listy **a, int min, int max)
{
	t_listy *temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->content >= min && temp_a->content < max)
			return (1);
		temp_a = temp_a->next;
	}
	return (0);
}

static void	split_chunk(t_listy **a, t_listy **b, int max, int min)
{
	t_listy	*temp_a;

	while (find_nums(a, min, max))
	{
		temp_a = *a;
		if (temp_a->content >= min && temp_a->content < max)
			push_b(a, b);
		else if (temp_a->next->content >= min && temp_a->next->content < max)
			swap_a(a);
		else if (lst_last(a)->content >= min && lst_last(a)->content < max)
			rev_rotate_a(a);
		else
			rotate_a(a);
	}
}

static int	find_min(t_listy **a)
{
	t_listy *temp_a;
	int		min;

	min = INT_MAX;
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->content < min)
			min = temp_a->content;
		temp_a = temp_a->next;
	}
	return (min);
}

int	big_sort(t_listy **a, t_listy **b, int median, int size)
{
	int		max;
	int		min;
	int		sorted;

	max = median / 2;
	min = find_min(a);
	sorted = 0;
	while (sorted < size)
	{
		temp_a = *a;
		split_chunk(a, b, max, min);
		sorted += lst_size(*b);
		sort_algo(a, b);
		min = max;
		max += max;
	}

	return (size);
}