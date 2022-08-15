/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:45:41 by aball             #+#    #+#             */
/*   Updated: 2022/08/05 00:07:24 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_listy **a_head, t_listy **b_head)
{
	t_listy *temp_a;

	temp_a = *a_head;
	if (temp_a->next)
		*a_head = temp_a->next;
	lst_add_front(b_head, new_lst(temp_a->content));
	free(temp_a);
	ft_printf("pb\n");
}

void push_a(t_listy **a_head, t_listy **b_head)
{
	t_listy *temp_b;

	temp_b = *b_head;
	*b_head = temp_b->next;
	lst_add_front(a_head, new_lst(temp_b->content));
	temp_b->next = NULL;
	free(temp_b);
	ft_printf("pa\n");
}