/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:47:48 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 22:51:08 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_listy **head)
{
	t_listy	*temp;
	t_listy	*last_node;

	temp = *head;
	while (temp->next)
		temp = temp->next;
	lst_add_front(head, new_lst(temp->content));
	temp = *head;
	while (temp->next->next)
		temp = temp->next;
	last_node = temp->next;
	temp->next = NULL;
	free(last_node);
}

void	rotate(t_listy **head)
{
	t_listy	*temp;

	temp = *head;
	*head = temp->next;
	temp->next = NULL;
	lst_add_back(head, new_lst(temp->content));
	free(temp);
}

void	rotate_ab(t_listy **a, t_listy **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
