/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:40:09 by aball             #+#    #+#             */
/*   Updated: 2022/07/01 21:45:43 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_listy **head)
{
	t_listy	*temp;

	temp = *head;
	lst_add_back(head, new_lst(temp->content, temp->index));
	*head = temp->next;
	temp->next = NULL;
	free(temp);
}


void	rev_rotate(t_listy **head)
{
	t_listy	*temp;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	lst_add_front(head, new_lst(temp->content, temp->index));
	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}
