/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:18:57 by aball             #+#    #+#             */
/*   Updated: 2022/07/03 23:43:07 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_listy **a)
{
	t_listy	*temp_a;

	temp_a = *a;
	if (is_sorted_a(a))
		return ;
	if (lst_last(*a)->index == 0)
	{
		if (temp_a->index == 2)
		{
			swap(a);
			ft_printf("sa\n");
		}
		rev_rotate(a);
		ft_printf("rra\n");
		return ;
	}
	if (temp_a->index == 1 && temp_a->next->index == 0)
	{
		rev_rotate(a);
		swap(a);
		rev_rotate(a);
		ft_printf("rra\nsa\rra");
		return ;
	}
	if (temp_a->index == 0 && is_sorted_a(a) == 0)
	{
		rotate(a);
		swap(a);
		rev_rotate(a);
		ft_printf("ra\nsa\nrra\n");
	}
	if (temp_a->index == 2 && temp_a->next->index == 0)
	{
		rotate(a);
		ft_printf("ra\n");
	}
	if (temp_a->index != 0 && temp_a->next->index != 0)
	{
		rotate(a);
		swap(a);
		ft_printf("ra\nsa\n");
	}
	exit (0);
}