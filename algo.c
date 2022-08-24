/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:35:21 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 14:08:05 by ballzball        ###   ########.fr       */
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

void	sort_algo(t_listy **a, t_listy **b)
{
	// t_listy	*temp_a;
	t_listy	*temp_b;

	// temp_a = *a;
	temp_b = *b;

	if (is_largest(b, temp_b))
		push_a(a, b);
	else if (is_smallest(b, temp_b))
		rotate_b(b);
	else if (is_smallest(b, temp_b->next))
	{
		swap_b(b);
	}
	else if (is_largest(b, temp_b->next))
		swap_b(b);
	else if (is_largest(b, lst_last(b)))
		rev_rotate_b(b);
	else
		rotate_b(b);
}