/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:22:48 by aball             #+#    #+#             */
/*   Updated: 2022/06/24 18:38:37 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_listy	**push_b(t_listy **a_head, t_listy **b_head, t_listy *node)
{
	t_listy	*temp;

	if (!a_head || !b_head || !node)
		ft_printf("you lost something in push_b");
	temp = *a_head;
	a_head = &temp->next;
	lst_add_front(b_head, new_lst(node->content, 0));
	ft_printf("pb\n");
	return (a_head);
}

void	sorting(t_listy *a)
{
	t_listy	**b;
	t_listy	**a_h;
	t_listy	*temp;
	t_listy	*current;

	b = (t_listy **)malloc(sizeof(t_listy **));
	// b = NULL;
	temp = a;
	a_h = push_b(&a, b, temp);
	current = *a_h;
	while (current)
	{
		// printf("%d\n", current->content);
		current = current->next;
	}
	current = *b;
	while(current)
		current = current->next;
}