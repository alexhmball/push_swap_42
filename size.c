/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:27:23 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 22:46:06 by aball            ###   ########.fr       */
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

int	is_smallest(t_listy **a, t_listy *node)
{
	t_listy	*current;

	current = *a;
	while (current)
	{
		if (current->content < node->content)
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
	while (current)
	{
		if (is_largest(head, current))
			break ;
		current = current->next;
		i++;
	}
	return (i);
}

int	smallest_position(t_listy **head)
{
	t_listy	*current;
	int		i;

	current = *head;
	i = 0;
	if (!*head)
		return (0);
	while (current)
	{
		if (is_smallest(head, current))
			break ;
		current = current->next;
		i++;
	}
	return (i);
}
