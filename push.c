/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:45:41 by aball             #+#    #+#             */
/*   Updated: 2022/07/03 18:52:10 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_listy **a_head, t_listy **b_head)
{
	t_listy *temp_a;

	if (!a_head || !b_head)
		ft_printf("you lost something in push_b\n");
	temp_a = *a_head;
	if (temp_a->next)
		*a_head = temp_a->next;
	lst_add_front(b_head, new_lst(temp_a->content, temp_a->index));
	free(temp_a);
}

void push_a(t_listy **a_head, t_listy **b_head)
{
	t_listy *temp_b;

	if (!a_head)
		ft_printf("you lost a_head in push_a\n");
	if (!b_head)
		ft_printf("you lost b_head in push_a\n");
	temp_b = *b_head;
	*b_head = temp_b->next;
	lst_add_front(a_head, new_lst(temp_b->content, temp_b->index));
	free(temp_b);
}