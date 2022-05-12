/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_db.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 22:41:05 by ballzball         #+#    #+#             */
/*   Updated: 2022/04/20 19:02:58 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_db(t_dlist **lst, t_dlist *new)
{
	new->next = *lst;
	new->prev = NULL;
	if(*lst)
		(*lst)->prev = new;
	*lst = new;
}