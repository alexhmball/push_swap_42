/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 18:51:22 by aball             #+#    #+#             */
/*   Updated: 2022/09/07 17:40:53 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_delone(t_listy *lst, void (*del)(void *))
{
	if (lst)
		del(&lst->content);
}

void	lst_clear(t_listy **lst, void (*del)(void *))
{
	t_listy	*clear;

	while (*lst)
	{
		clear = (*lst)->next;
		lst_delone(*lst, del);
		*lst = clear;
	}
}

void	free_double(char **nums, int error)
{
	int	i;

	i = 0;
	while (nums[i])
		free(nums[i++]);
	free (nums);
	if (error)
		exit (0);
}
