/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:48 by aball             #+#    #+#             */
/*   Updated: 2022/06/24 21:20:16 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listy	**push_b(t_listy **a_head, t_listy **b_head)
{
	t_listy	*temp_a;
	// t_listy	*temp_b;

	if (!a_head || !b_head)
		ft_printf("you lost something in push_b\n");
	// temp_b = *a_head;
	temp_a = *a_head;
	temp_a = temp_a->next;
	lst_add_front(b_head, *a_head);
	ft_printf("pb\n");
	a_head = &temp_a;
	return (a_head);
	// b_head = &temp_b;
}

void	push_a(t_listy **a_head, t_listy **b_head)
{
	t_listy	*temp_a;
	t_listy	*temp_b;

	if(!a_head)
		ft_printf("you lost a_head in push_a\n");
	if (!b_head)
		ft_printf("you lost b_head in push_a\n");
	temp_b = *b_head;
	temp_a = *b_head;
	if (!temp_b->next)
		temp_b = NULL;
	else
		temp_b = temp_b->next;
	lst_add_front(a_head, *b_head);
	ft_printf("pa\n");
	b_head = &temp_b;
	a_head = &temp_a;
}

void	sorting(t_listy *a)
{
	t_listy	**b;
	t_listy	**a_h;
	t_listy	*current;

	b = (t_listy **)malloc(sizeof(t_listy **));
	*b = NULL;
	a_h = &a;
	a_h = push_b(a_h, b);
	free (a);
	push_a(a_h, b);
	current = *a_h;
	while (current)
	{
		// printf("%d\n", current->content);
		current = current->next;
	}
	// current = *b;
	// while(current)
	// 	current = current->next;
}