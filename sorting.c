/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:48 by aball             #+#    #+#             */
/*   Updated: 2022/08/07 15:37:18 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_median(int *nums, int ac)
{
	int	i;
	int	x;
	int temp;

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
	ft_printf("%d", nums[2]);
	return (nums[2]);
}

void	sorting(t_listy **a, int size, int median)
{
	t_listy	**b;
	t_listy	*temp_a;
	t_listy	*temp_b;

	b = (t_listy **)malloc(sizeof(t_listy **));
	temp_a = *a;
	if (size == 2 && is_sorted_a(a) == 0)
	{
		swap(a);
		ft_printf("sa\n");
	}
	else if (size == 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size == 5)
		sort_five(a, b);
	size /= 2;
	while (lst_size(*a) > 4 && is_sorted_a(a) == 0)
	{
		if (lst_size(*b) > 1 && temp_a->content < median)
		{
			temp_b = *b;
			if (is_largest(b, lst_last(b)))
				rev_rotate_b(b);
			else if (temp_b->next->content > temp_b->content)
				swap_b(b);
			push_b(a, b);
		}
		else if (lst_size(*b) > 1)
		{
			temp_b = *b;
			if (is_largest(b, lst_last(b)) && lst_last(a)->content < median)
				rev_rotate_ab(a, b);
			else if (is_largest(b, temp_b->next) && temp_a->next->content < median)
				swap_a_b(a, b);
			temp_a = *a;
			if (temp_a->content < median)
				push_b(a, b);
		}
		else
		{
			if (temp_a->content < median)
				push_b(a, b);
			else if (temp_a->next->content < median)
				rotate_a(a);
			else
				rev_rotate_a(a);
			temp_a = *a;
		}
	}
	// while (is_sorted_a(a) == 0 || is_sorted_b(b) == 0)
	// 	sort_algo(a, b);
	temp_b = *b;
	while (temp_b)
	{
		push_a(a, b);
		temp_b = *b;
	}
	temp_a = *a;
	// while (temp_a)
	// {
	// 	ft_printf("%d\n", temp_a->content);
	// 	temp_a = temp_a->next;
	// }
	
}