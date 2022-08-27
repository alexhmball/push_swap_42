/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:28:45 by aball             #+#    #+#             */
/*   Updated: 2022/08/27 18:21:58 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_location(t_listy **a, int top, int bottom)
{
	t_listy	*temp_a;
	int		i;

	temp_a = *a;
	i = 1;
	while (temp_a)
	{
		if (temp_a->content <= top && temp_a->content >= bottom)
			return (i);
		i++;
		temp_a = temp_a->next;
	}
	return (0);
}

static int	split_list(t_listy **a, t_listy **b, int top, int bottom, int size)
{
	t_listy	*temp_a;
	int		flag;

	temp_a = *a;
	flag = 2;
	if (temp_a->content <= top && temp_a->content >= bottom)
	{
		push_b(a, b);
		flag = 1;
	}
	else if (find_location(a, top, bottom) == 0)
		return (0);
	else if (find_location(a, top, bottom) == 1)
		swap_a(a);
	else if (find_location(a, top, bottom) > size)
	{
		while (!(temp_a->content <= top && temp_a->content >= bottom))
		{
			rev_rotate_a(a);
			temp_a = *a;
		}
	}
	else if (find_location(a, top, bottom) <= size)
	{
		while (!(temp_a->content <= top && temp_a->content >= bottom))
		{
			rotate_a(a);
			temp_a = *a;
		}
	}
	return (flag);
}

int	big_sort(t_listy **a, t_listy **b, int median, int size)
{
	static int	flag;
	static int	top;
	static int	bottom;
	static int	sorted;
	int			i;
	int			f;

	i = 0;
	f = 3;
	if (flag == 0)
	{
		top = median;
		bottom = median;
		while (lst_size(*b) < 10 && sorted + lst_size(*b) < size)
		{
			if (f == 0)
			{
				top++;
				bottom--;
			}
			f = split_list(a, b, top, bottom, size / 2);
		}
		flag = 1;
	}
	if (flag == 1)
	{
		i = top;
		while (lst_size(*b) < 10 && sorted + lst_size(*b) < size)
		{
			if (f == 0)
				top++;
			f = split_list(a, b, top, i, size / 2);
		}
		flag = 2;
	}
	if (flag == 2)
	{
		i = bottom;
		while (lst_size(*b) < 10 && sorted + lst_size(*b) < size)
		{
			if (f == 0)
				bottom--;
			f = split_list(a, b, i, bottom, size / 2);
		}
		flag = 1;
	}
	size = lst_size(*b);
	sorted += size;
	sort_algo(a, b);
	return (size);
}