/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ballzball <ballzball@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:30:30 by aball             #+#    #+#             */
/*   Updated: 2022/08/28 14:20:37 by ballzball        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		i++;
	}
	return (i);
}

static t_listy	**create_list(int *nums, int ac)
{
	int		i;
	t_listy	**head;
	t_listy	*current;
	t_listy	*temp;

	i = 0;
	head = (t_listy **)malloc(sizeof(t_listy **));
	head = &current;
	current = new_lst(nums[i]);
	lst_add_back(head, current);
	temp = *head;
	i++;
	while (i < ac)
	{
		head = &temp;
		current = new_lst(nums[i]);
		lst_add_back(head, current);
		i++;
	}
	return (head);
}

int	main(int ac, char **av)
{
	char	*nums;
	char	**only_nums;
	int		*numbers;
	int		median;
	t_listy	*a;

	nums = NULL;
	nums = error_handler(ac, av, nums);
	only_nums = ft_split(nums, ' ');
	ac = count_nums(only_nums);
	free (nums);
	numbers = check_duplicates(only_nums);
	free (only_nums);
	a = *create_list(numbers, ac);
	median = find_median(numbers, ac);
	sorting(&a, ac, median, numbers);
	return (0);
}
