/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 00:03:13 by aball             #+#    #+#             */
/*   Updated: 2022/08/28 17:10:30 by aball            ###   ########.fr       */
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

static int	find_position(t_listy **a, int top, int bottom)
{
	t_listy	*temp_a;
	int		i;

	temp_a = *a;
	i = 0;
	while (temp_a)
	{
		if (temp_a->content > top && temp_a->content <= bottom)
			break;
		i++;
		temp_a = temp_a->next;
	}
	return (i);
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
		else if (find_position(a, top, bottom) > lst_size(*a) / 2)
			rev_rotate_a(a);
		else if (lst_last(a)->content > top && lst_last(a)->content <= bottom)
			rev_rotate_a(a);
		else
			rev_rotate_a(a);
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

static int	find_node(t_listy **head, int content)
{
	t_listy	*temp;
	int		i;

	i = 0;
	temp = *head;
	while (temp)
	{
		if (temp->content == content)
			break;
		i++;
		temp = temp->next;
	}
	return (i);
}

int	big_sort(t_listy **a, t_listy **b, int *nums, int size)
{
	t_listy	*temp_a;
	int		top;
	int		bottom;
	int		sorted;
	int		min;
	int		i;

	i = 15;
	top = nums[i];
	bottom = find_max(a);
	sorted = 0;
	split_chunk(a, b, top, bottom);
	sorted += lst_size(*b);
	min = find_min(b);
	sort_algo(a, b);
	bottom = top;
	i += 30;
	top -= nums[i];
	temp_a = *a;
	while (sorted < size)
	{
		split_chunk(a, b, top, bottom);
		sorted += lst_size(*b);
		temp_a = *a;
		while (temp_a->content != min)
		{
			if (find_node(a, min) > size / 2)
				rev_rotate_a(a);
			else
				rotate_a(a);
			temp_a = *a;
		}
		min = find_min(b);
		sort_algo(a, b);
		bottom = top;
		i += 30;
		if (i > size)
			i = size;
		top -= nums[i];
	}
	return (size);
}