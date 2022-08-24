/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:48 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 20:46:51 by ballzball        ###   ########.fr       */
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
	i /= 2;
	return (nums[i]);
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

static int	find_nums_left(t_listy **a, int median)
{
	t_listy	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->content >= median)
			return (1);
		temp_a = temp_a->next;
	}
	return (0);
}

static int	find_upper_half(t_listy **a, int median)
{
	t_listy	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->content < median)
			return (1);
		temp_a = temp_a->next;
	}
	return (0);
}

static int	split_list_lower(t_listy **a, t_listy **b, int median)
{
	t_listy	*temp_a;
	int		i;
	// t_listy	*temp_b;

	i = 0;
	while (find_nums_left(a, median))
	{
		temp_a = *a;
		// temp_b = *b;
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


void	sorting(t_listy **a, int size, int median)
{
	t_listy	**b;
	t_listy	*temp_b;
	// t_listy	*temp_a;
	int		i;

	b = (t_listy **)malloc(sizeof(t_listy **));
	// temp_a = *a;
	if (size < 6)
		small_sort(a, b, size);
	else
	{
		i = split_list_lower(a, b, median);
		sort_algo(a, b);
		while (lst_last(a)->content < median)
		{
			rev_rotate_a(a);
			i--;
		}
		while (find_upper_half(a, median))
			push_b(a, b);
		sort_algo(a, b);
	}
	temp_b = *b;
	while (temp_b)
	{
		push_a(a, b);
		temp_b = *b;
	}
}
