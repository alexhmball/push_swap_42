/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:23:05 by aball             #+#    #+#             */
/*   Updated: 2022/09/02 16:18:01 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_size(t_listy *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

//create a new node
t_listy	*new_lst(int content)
{
	t_listy	*new;

	new = (t_listy *)malloc(sizeof(t_listy));
	if (!new)
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}

//adds a new node to the end of the list
void	lst_add_front(t_listy **lst, t_listy *new)
{
	if (!lst)
		return ;
	if (!*lst)
		new->next = NULL;
	else
		new->next = *lst;
	*lst = new;
}

//adds a node to the front of the list
void	lst_add_back(t_listy **lst, t_listy *node)
{
	t_listy	*temp;

	temp = *lst;
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = node;
		node->next = NULL;
		return ;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = node;
	node->next = NULL;
}

t_listy	*lst_last(t_listy **lst)
{
	t_listy	*temp;

	temp = *lst;
	if (!temp)
		return (0);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
