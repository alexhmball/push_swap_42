/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:48 by aball             #+#    #+#             */
/*   Updated: 2022/08/04 19:50:33 by aball            ###   ########.fr       */
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
	return (nums);
}

void	sorting(t_listy *a, int size)
{
	t_listy	**b;
	t_listy	*current;
	int		i;

	b = (t_listy **)malloc(sizeof(t_listy **));
	i = 0;
	current = a;
	if (size == 2 && is_sorted_a(&a) == 0)
	{
		swap(&a);
		ft_printf("sa\n");
	}
	if (size == 3)
		sort_three(&a);
	else if (size == 4)
		sort_four(&a, b);
	// else if (size == 5)
	// 	sort_five(&a, b);
	// if (is_sorted_a(&a) == 1)
	// 	return ;
	// while (i < size && is_sorted_a(&a) == 0)
	// {
	// 	if (current->index < size / 2)
	// 	{
	// 		push_b(&a, b);
	// 		current = current->next;
	// 		ft_printf("pb\n");
	// 	}
	// 	else
	// 	{
	// 		current = current->next;
	// 		rotate_a(&a);
	// 		ft_printf("ra\n");
	// 	}
	// 	i++;
	// }
	// current = a;
	// ft_printf("a  i\n");
	// while (current)
	// {
	// 	ft_printf("%d  ", current->content);
	// 	ft_printf("%d\n", current->index);
	// 	current = current->next;
	// }
	// current = *b;
	// printf("\nb  i\n");
	// while (current)
	// {
	// 	ft_printf("%d  ", current->content);
	// 	ft_printf("%d\n", current->index);
	// 	current = current->next;
	// }
	// sort_algo(&a, b);
	// current = a;
	// ft_printf("a  i\n");
	// while (current)
	// {
	// 	ft_printf("%d  ", current->content);
	// 	ft_printf("%d\n", current->index);
	// 	current = current->next;
	// }
	// current = *b;
	// printf("\nb  i\n");
	// while(current)
	// {
	// 	ft_printf("%d  ", current->content);
	// 	ft_printf("%d\n", current->index);
	// 	current = current->next;
	// }
}