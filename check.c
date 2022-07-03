/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:36:43 by aball             #+#    #+#             */
/*   Updated: 2022/07/03 18:59:25 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_listy **a_head)
{
	t_listy	*current;

	current = *a_head;
		while (current->next)
		{
			if (current->index + 1 != current->next->index)
				return (0);
			current = current->next;
		}
		return (1);
}

int is_sorted_b(t_listy **b_head)
{
	t_listy *current;

	current = *b_head;
	if (*b_head)
	{
		while (current->next)
		{
			if (current->index - 1 != current->next->index)
				return (0);
			current = current->next;
		}
		return (1);
	}
	else
		return (0);
}