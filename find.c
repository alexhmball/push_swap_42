/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:39:00 by aball             #+#    #+#             */
/*   Updated: 2022/08/28 18:20:09 by aball            ###   ########.fr       */
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

int	find_nums_left(t_listy **a, int median)
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

int	find_upper_half(t_listy **a, int median)
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

int	find_max(t_listy **a)
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

int	find_min(t_listy **a)
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
