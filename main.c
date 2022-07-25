/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:30:30 by aball             #+#    #+#             */
/*   Updated: 2022/07/25 22:59:17 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_nums(char *nums)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (nums[i])
	{
		if (nums[i] == ' ')
			size++;
		i++;
	}
	return (size);
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
	current = new_lst(nums[i], i);
	lst_add_back(head, current);
	temp = *head;
	i++;
	while (i < ac)
	{
		head = &temp;
		current = new_lst(nums[i], i);
		lst_add_back(head, current);
		i++;
	}
	nums = pre_sort(nums, ac);
	i = 0;
	current = *head;
	while (i < ac)
	{
		current = *head;
		while (current)
		{
			if (current->content == nums[i])
				current->index = i;
			current = current->next;
			// ft_printf("%d ", current->content);
		}
		i++;
	}
	current = *head;
	return (head);
}

static void	check_and_error(int *numbers)
{
	int	i;
	int	x;

	i = 0;
	while (numbers[i])
	{
		x = i + 1;
		while (numbers[x])
		{
			if (numbers[i] == numbers[x])
			{
				free(numbers);
				print_error(3);
			}
			x++;
		}
		i++;
	}
}

static int	*check_duplicates(char **nums)
{
	int	i;
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
	check_and_error(numbers);
	return (numbers);
}

static char	*error_handler(int ac, char **av, char *nums)
{
	int	i;

	i = 0;
	if (ac < 2)
	{
		print_error(2);
		exit (1);
	}
	nums = str_sep(ac - 1, av + 1, " ");
	// ft_printf("|%s|\n", nums);
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
	t_listy	**a;

	nums = NULL;
	nums = error_handler(ac, av, nums);
	ac = count_nums(nums) + 1;
	only_nums = ft_split(nums, ' ');
	free (nums);
	numbers = check_duplicates(only_nums);
	a = create_list(numbers, ac);
	sorting(*a, ac);
	return (0);
}
