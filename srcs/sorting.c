/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:48 by aball             #+#    #+#             */
/*   Updated: 2022/09/02 18:34:57 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sort(t_listy **a, t_listy **b, int size)
{
	t_listy	*temp_b;

	if (size == 2 && is_sorted_a(a) == 0)
		swap_a(a);
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	if (size > 3)
	{
		temp_b = *b;
		while (temp_b)
		{
			push_a(a, b);
			temp_b = *b;
		}
	}
}

int	split_list_lower(t_listy **a, t_listy **b, int median)
{
	t_listy	*temp_a;
	int		i;

	i = 0;
	while (find_nums_left(a, median))
	{
		temp_a = *a;
		if (temp_a->content >= median)
		{
			push_b(a, b);
			i++;
		}
		else if (temp_a->next->content >= median)
			swap_a(a);
		else if (lst_last(a)->content >= median)
			rev_rotate_a(a);
		else
			rotate_a(a);
	}
	return (i);
}

static void	medium_sort(t_listy **a, t_listy **b, int median)
{
	split_list_lower(a, b, median);
	sort_algo(a, b);
	while (lst_last(a)->content < median)
		rev_rotate_a(a);
	while (find_upper_half(a, median))
		push_b(a, b);
	sort_algo(a, b);
}

int	*find_pivot(int *nums, int ac)
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
	return (nums);
}

void	sorting(t_listy **a, int size, int median, int *numbers)
{
	t_listy	**b;
	int		*pivot;

	b = (t_listy **)malloc(sizeof(t_listy **));
	*b = NULL;
	if (size < 6)
		small_sort(a, b, size);
	else
	{
		if (size <= 50 && is_sorted_a(a) == 0)
			medium_sort(a, b, median);
		else if (is_sorted_a(a) == 0)
		{
			pivot = find_pivot(numbers, size);
			big_sort(a, b, pivot, size);
		}
	}
	free(b);
}
