/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:28:45 by aball             #+#    #+#             */
/*   Updated: 2022/08/28 00:01:16 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_nums(t_listy **a, int top, int bottom)
{
	t_listy *temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->content > top && temp_a->content <= bottom)
			return (1);
		temp_a = temp_a->next;
	}
	return (0);
}

static void	split_chunk(t_listy **a, t_listy **b, int top, int bottom)
{
	t_listy	*temp_a;

	while (find_nums(a, top, bottom))
	{
		temp_a = *a;
		if (temp_a->content > top && temp_a->content <= bottom)
			push_b(a, b);
		else if (temp_a->next->content > top && temp_a->next->content <= bottom)
			swap_a(a);
		else if (lst_last(a)->content > top && lst_last(a)->content <= bottom)
			rev_rotate_a(a);
		else
			rotate_a(a);
	}
}

static int	find_max(t_listy **a)
{
	t_listy	*temp_a;
	int		min;

	min = INT_MIN;
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->content > min)
			min = temp_a->content;
		temp_a = temp_a->next;
	}
	return (min);
}

static int	find_min(t_listy **a)
{
	t_listy	*temp_a;
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
	t_listy	*temp_a;
	int		top;
	int		bottom;
	int		sorted;
	int		min;

	top = median + (median/2);
	bottom = find_max(a);
	sorted = 0;
	split_chunk(a, b, top, bottom);
	sorted += lst_size(*b);
	min = find_min(b);
	sort_algo(a, b);
	bottom = top;
	top -= top - (top/2);
	temp_a = *a;
	while (sorted < size)
	{
		split_chunk(a, b, top, bottom);
		sorted += lst_size(*b);
		temp_a = *a;
		while (temp_a->content != min)
		{
			rotate_a(a);
			temp_a = *a;
			// ft_printf("min: %d\n", min);
			// ft_printf("a head: %d\n", temp_a->content);
		}
		min = find_min(b);
		sort_algo(a, b);
		bottom = top;
		top -= top - (top/2);
	}
	return (size);
}