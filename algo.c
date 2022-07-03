/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:35:21 by aball             #+#    #+#             */
/*   Updated: 2022/07/03 19:54:12 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_lst(t_listy **a, t_listy **b)
{
	t_listy	*temp_a;
	t_listy	*temp_b;
	// t_listy	*temp;

	temp_a = *a;
	temp_b = *b;
	while (is_sorted_a(a) == 0 || is_sorted_b(b) == 0)
	{
		if (temp_b->index - 1 == temp_a->index)
		{
			push_a(a, b);
			ft_printf("pa\n");
		}
		else if (temp_b->index + 1 == temp_a->index)
		{
			push_b(a, b);
			ft_printf("pb\n");
		}
		else if (lst_last(*b)->index > temp_b->index && lst_last(*a)->index < temp_a->index)
		{
			rev_rotate(b);
			rev_rotate(a);
			temp_a = *a;
			temp_b = *b;
			ft_printf("rrr\n");
		}
		else if (lst_last(*b)->index > temp_b->index)
		{
			rev_rotate(b);
			temp_b = *b;
			ft_printf("rrb\n");
		}
		else if (lst_last(*a)->index < temp_a->index)
		{
			rev_rotate(a);
			temp_a = *a;
			ft_printf("rra\n");
		}
		else if (temp_b->index > lst_last(*b)->index && temp_a->index > lst_last(*a)->index)
		{
			temp_a = temp_a->next;
			temp_b = temp_b->next;
			rotate(a);
			rotate(b);
			ft_printf("rr\n");
		}
		else if (temp_b->index > lst_last(*b)->index)
		{
			temp_b = temp_b->next;
			rotate(b);
			ft_printf("rb\n");
		}
		else if (temp_a->index > lst_last(*a)->index)
		{
			temp_a = temp_a->next;
			rotate(a);
			ft_printf("ra");
		}
		else if (temp_b->index < temp_b->next->index && temp_a->index > temp_a->next->index)
		{
			swap(a);
			swap(b);
			ft_printf("ss\n");
		}
		else if (temp_b->index < temp_b->next->index)
		{
			swap(b);
			ft_printf("sb\n");
		}
		else if (temp_a->index > temp_a->next->index)
		{
			swap(a);
			ft_printf("sa\n");
		}
	}
}

void	sort_algo(t_listy **a_head, t_listy **b_head)
{
	sort_lst(a_head, b_head);
	while (*b_head)
	{
		push_a(a_head, b_head);
		ft_printf("pa\n");
	}
	// ft_printf("it's sorted\n");
}