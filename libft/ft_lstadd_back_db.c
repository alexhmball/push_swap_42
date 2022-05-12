/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_db.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:41:01 by ballzball         #+#    #+#             */
/*   Updated: 2022/04/20 02:46:55 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_db(t_dlist **lst, t_dlist *new)
{	
	t_dlist	*last;
	
	last = *lst;
	new->next = NULL;
	if (!*lst)
	{
		new->prev = NULL;
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}