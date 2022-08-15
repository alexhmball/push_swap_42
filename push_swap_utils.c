/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:23:05 by aball             #+#    #+#             */
/*   Updated: 2022/08/05 02:48:11 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int flag)
{
	char *error;

	if (flag == 1)
	{
		error = "Error\nPlease enter only numbers\n";
		write(2, error, ft_strlen(error));
	}
	if (flag == 2)
	{
		error = "Error\nPlease provide numbers to sort\n";
		write(2, error, ft_strlen(error));
	}
	if (flag == 3)
	{
		error = "Error\nPlease remove duplicate numbers\n";
		write(2, error, ft_strlen(error));
	}
	exit (1);
}

int	lst_size(t_listy *lst)
{
	int i;

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
	t_listy *temp;

	temp = *lst;
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = node;
		node->next = NULL;
		return;
	}
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = node;
	node->next = NULL;
}

t_listy *lst_last(t_listy **lst)
{
	t_listy	*temp;
	
	temp = *lst;
	if (!temp)
		return (0);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
