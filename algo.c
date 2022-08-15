/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:35:21 by aball             #+#    #+#             */
/*   Updated: 2022/08/07 15:33:58 by ballzball        ###   ########.fr       */
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

// void	sort_algo(t_listy **a, t_listy **b)
// {
// 	t_listy	*temp_a;
// 	t_listy	*temp_b;

// 	temp_a = *a;
// 	temp_b = *b;
// }