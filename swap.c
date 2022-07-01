/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:36:25 by aball             #+#    #+#             */
/*   Updated: 2022/07/01 23:13:06 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_listy **head)
{
	t_listy	*temp1;
	t_listy	*temp2;
	t_listy	*temp3;

	temp3 = (t_listy *)malloc(sizeof(t_listy *));
	temp1 = *head;
	temp2 = temp1->next;
	temp3->content = temp2->content;
	temp3->index = temp2->index;
	temp2->content = temp1->content;
	temp2->index = temp1->index;
	temp1->content = temp3->content;
	temp1->index = temp3->index;
	free(temp3);
}
