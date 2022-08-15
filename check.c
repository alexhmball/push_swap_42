/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:36:43 by aball             #+#    #+#             */
/*   Updated: 2022/08/06 21:06:37 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_a(t_listy **a_head)
{
	t_listy	*current;

	current = *a_head;
	if (!*a_head)
		return (1);
	while (current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int is_sorted_b(t_listy **b_head)
{
	t_listy *current;

	current = *b_head;
	if (!*b_head)
		return (1);
	while (current->next)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}