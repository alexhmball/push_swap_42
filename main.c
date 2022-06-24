/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:30:30 by aball             #+#    #+#             */
/*   Updated: 2022/06/24 16:52:32 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_listy	*create_list(int *nums)
{
	int	i;
	t_listy **head;
	t_listy *current;
	t_listy	*temp;

	i = 0;
	head = &current;
	current = new_lst(nums[i], i);
	lst_add_back(head, current);
	temp = *head;
	i++;
	while (nums[i])
	{
		head = &temp;
		current = new_lst(nums[i], i);
		lst_add_back(head, current);
		i++;
	}
	return (temp);
}

static int	*check_duplicates(char **nums)
{
	int	i;
	int	x;
	int	*numbers;

	i = 0;
	while (nums[i])
		i++;
	numbers = (int *)malloc(i * sizeof(int *));
	if (!numbers)
		return (0);
	i = 0;
	while (nums[i])
	{
		numbers[i] = ft_atoi(nums[i]);
		i++;
	}
	i = 0;
	while (numbers[i])
	{
		x = i + 1;
		while (numbers[x])
		{
			if (numbers[i] == numbers[x])
			{
				free (numbers);
				print_error(3);
			}
			x++;
		}
		i++;
	}
	return (numbers);
}

static char	*error_handler(int ac, char **av, char *nums)
{
	int		i;

	i = 0;
	if (ac < 2)
	{
		print_error(2);
		exit (1);
	}
	nums = str_sep(ac - 1, av + 1, " ");
	while (nums[i])
	{
		if (ft_isdigit(nums[i]) == 0 && nums[i] != ' ' && nums[i] != '-')
		{
			print_error(1);
			exit (1);
		}
		i++;
	}
	return (nums);
}

int	main(int ac, char **av)
{
	char	*nums;
	char	**only_nums;
	int		*numbers;
	t_listy	*a;
	// t_listy	*b;

	a = (t_listy *)malloc(sizeof(t_listy *));
	nums = NULL;
	nums = error_handler(ac, av, nums);
	only_nums = ft_split(nums, ' ');
	free (nums);
	numbers = check_duplicates(only_nums);
	a = create_list(numbers);
	while (a)
	{
		ft_printf("%d\n", a->content);
		a = a->next;
	}
	sorting(a);
	return (0);
}