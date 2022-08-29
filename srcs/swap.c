/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:36:25 by aball             #+#    #+#             */
/*   Updated: 2022/08/29 16:43:56 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_listy **head)
{
	t_listy	*temp1;
	t_listy	*temp2;
	t_listy	*temp3;

	temp3 = (t_listy *)malloc(sizeof(t_listy *));
	temp1 = *head;
	temp2 = temp1->next;
	temp3->content = temp2->content;
	temp2->content = temp1->content;
	temp1->content = temp3->content;
	free(temp3);
	ft_printf("sa\n");
}

void	swap_b(t_listy **head)
{
	t_listy	*temp1;
	t_listy	*temp2;
	t_listy	*temp3;

	temp3 = (t_listy *)malloc(sizeof(t_listy *));
	temp1 = *head;
	temp2 = temp1->next;
	temp3->content = temp2->content;
	temp2->content = temp1->content;
	temp1->content = temp3->content;
	free(temp3);
	ft_printf("sb\n");
}

void	swap(t_listy **head)
{
	t_listy	*temp1;
	t_listy	*temp2;
	t_listy	*temp3;

	temp3 = (t_listy *)malloc(sizeof(t_listy *));
	temp1 = *head;
	temp2 = temp1->next;
	temp3->content = temp2->content;
	temp2->content = temp1->content;
	temp1->content = temp3->content;
	free(temp3);
}

void	swap_a_b(t_listy **a, t_listy **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
