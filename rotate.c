/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:40:09 by aball             #+#    #+#             */
/*   Updated: 2022/07/29 23:27:43 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_listy **head)
{
	t_listy	*temp;

	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	lst_add_back(head, new_lst(temp->content, temp->index));
	free(temp);
	ft_printf("ra\n");
}

void	rotate_b(t_listy **head)
{
	t_listy	*temp;

	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	lst_add_back(head, new_lst(temp->content, temp->index));
	free(temp);
	ft_printf("rb\n");
}


void	rev_rotate_a(t_listy **head)
{
	t_listy	*temp;
	t_listy	*last_node;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	lst_add_front(head, new_lst(temp->content, temp->index));
	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	free(last_node);
	ft_printf("rra\n");
}

void	rev_rotate_b(t_listy **head)
{
	t_listy	*temp;
	t_listy	*last_node;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	lst_add_front(head, new_lst(temp->content, temp->index));
	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	free(last_node);
	ft_printf("rrb\n");
}
