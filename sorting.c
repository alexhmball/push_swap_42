/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:48 by aball             #+#    #+#             */
/*   Updated: 2022/07/01 23:33:55 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*pre_sort(int *nums, int ac)
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
			if (nums[i] < nums[x])
			{
				temp = nums[i];
				nums[i] = nums[x];
				nums[x] = temp;
			}
			x++;
		}
		i++;
	}
	i = 0;
	// while (nums[i])
	// {
	// 	ft_printf("%d", nums[i++]);
	// }
	return (nums);
}

void	sorting(t_listy *a, int size)
{
	t_listy	**b;
	t_listy	*current;

	b = (t_listy **)malloc(sizeof(t_listy **));
	current = a;
	while (current)
	{
		if (current->index < size)
			push_b(&a, b);
		else
			rotate(&a);
		current = current->next;
	}
	// push_b(&a, b);
	// push_b(&a, b);
	// push_a(&a, b);
	// swap(&a);
	// rotate(&a);
	// rev_rotate(&a);
	current = a;
	ft_printf("a  i\n");
	while (current)
	{
		ft_printf("%d  ", current->content);
		ft_printf("%d\n", current->index);
		current = current->next;
	}
	current = *b;
	printf("\nb  i\n");
	while(current)
	{
		ft_printf("%d  ", current->content);
		ft_printf("%d\n", current->index);
		current = current->next;
	}
}