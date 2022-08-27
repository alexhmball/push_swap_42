/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:28:45 by aball             #+#    #+#             */
/*   Updated: 2022/08/27 23:03:23 by ballzball        ###   ########.fr       */
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
	t_listy *temp_a;
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

int	big_sort(t_listy **a, t_listy **b, int median, int size)
{
	t_listy	*temp_a;
	int		top;
	int		bottom;
	int		sorted;

	top = median + (median/2);
	bottom = find_max(a);
	sorted = 0;
	temp_a = *a;
	while (sorted < size)
	{
		split_chunk(a, b, top, bottom);
		sorted += lst_size(*b);
		while (!(temp_a->content <= bottom))
			rotate_a(a);
		sort_algo(a, b);
		bottom = top;
		top -= top - (top/2);
	}

	return (size);
}