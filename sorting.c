/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:48 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 14:01:22 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(int *nums, int ac)
{
	int	i;
	int	x;
	int	temp;

	i = 0;
	while (i < ac)
	{
		x = 0;
		while (x < ac)
		{
			if (nums[i] > nums[x])
			{
				temp = nums[i];
				nums[i] = nums[x];
				nums[x] = temp;
			}
			x++;
		}
		i++;
	}
	return (nums[2]);
}

static void	small_sort(t_listy **a, t_listy **b, int size)
{
	if (size == 2 && is_sorted_a(a) == 0)
		swap_a(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
}

static void	split_list(t_listy **a, t_listy **b, int median)
{
	t_listy	*temp_a;
	t_listy	*temp_b;

	while (lst_size(*a) >= 4 && is_sorted_a(a) == 0)
	{
		temp_a = *a;
		temp_b = *b;
		if (lst_size(*b) > 1 && is_smallest(b, temp_b))
		{
			if (temp_a->content >= median)
				rotate_ab(a, b);
			else
				rotate_b(b);
		}
		else if (lst_size(*b) > 2 && is_smallest(b, temp_b->next))
		{
			if (temp_a->content >= median)
			{
				swap_a_b(a, b);
				rotate_b(b);
			}
			else
			{
				swap_b(b);
				rotate_b(b);
			}
		}
		else if (lst_size(*b) > 1 && is_largest(b, lst_last(b)))
		{
			if (temp_a->content >= median)
				rev_rotate_ab(a, b);
			else
				rev_rotate_b(b);
		}
		else if (lst_size(*b) > 1 && is_largest(b, temp_b->next))
		{
			if (temp_a->content >= median)
				swap_a_b(a, b);
			else
				swap_b(b);
		}
		else if (temp_a->content < median)
			push_b(a, b);
		else if (temp_a->content >= median)
			rotate_a(a);
	}
}

void	sorting(t_listy **a, int size, int median)
{
	t_listy	**b;
	// t_listy	*temp_a;
	t_listy	*temp_b;

	b = (t_listy **)malloc(sizeof(t_listy **));
	// temp_a = *a;
	small_sort(a, b, size);
	split_list(a, b, median);
	if (is_sorted_a(a) == 0)
		sort_three(a);
	while (is_sorted_b(b) == 0)
		sort_algo(a, b);
	temp_b = *b;
	while (temp_b)
	{
		push_a(a, b);
		temp_b = *b;
	}
}
