/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:52:25 by aball             #+#    #+#             */
/*   Updated: 2022/08/24 22:58:18 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(int flag)
{
	char	*error;

	if (flag == 1)
	{
		error = "Error\n";
		write(2, error, 6);
	}
	if (flag == 2)
	{
		error = "Error\n";
		write(2, error, 6);
	}
	if (flag == 3)
	{
		error = "Error\n";
		write(2, error, 6);
	}
	exit (1);
}

int	*check_duplicates(char **nums)
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

char	*error_handler(int ac, char **av, char *nums)
{
	int	i;

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

void	check_and_error(int *numbers)
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
