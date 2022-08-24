/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:35:21 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 19:47:46 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_largest(t_listy **head, t_listy *node)
{
	t_listy	*current;

	current = *head;
	if (!*head)
		return (0);
	while (current)
	{
		if (current->content > node->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	largest_position(t_listy **head)
{
	t_listy	*current;
	int		i;

	current = *head;
	i = 0;
	if (!*head)
		return (0);
	while(current)
	{
		if (is_largest(head, current))
			break ;
		current = current->next;
		i++;
	}
	return (i);
}

void	sort_algo(t_listy **a, t_listy **b)
{
	// t_listy	*temp_a;
	t_listy	*temp_b;

	while (lst_size(*b) != 0)
	{
		// temp_a = *a;
		temp_b = *b;
		if (is_largest(b, temp_b))
			push_a(a, b);
		else if (largest_position(b) == 1)
			swap_b(b);
		else if (largest_position(b) > lst_size(*b) / 2)
		{
			while (is_largest(b, temp_b) == 0)
			{
				rev_rotate_b(b);
				temp_b = *b;
			}
		}
		else if (largest_position(b) < lst_size(*b) / 2)
		{
			while (is_largest(b, temp_b) == 0)
			{
				rotate_b(b);
				temp_b = *b;
			}
		}
		else
			rotate_b(b);
	}
}