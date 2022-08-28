/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:52:25 by aball             #+#    #+#             */
/*   Updated: 2022/08/29 00:59:29 by aball            ###   ########.fr       */
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
}

int	*check_duplicates(char **nums)
{
	int	i;
	int	*numbers;

	i = 0;
	while (nums[i])
		i++;
	numbers = (int *)ft_calloc(i, sizeof(int *));
	if (!numbers)
		return (0);
	i = 0;
	while (nums[i])
	{
		numbers[i] = ft_atoi(nums[i]);
		i++;
	}
	if (!check_and_error(numbers))
	{
		free_double(nums);
		exit (0);
	}
	return (numbers);
}

char	*error_handler(int ac, char **av, char *nums)
{
	int	i;

	i = 0;
	if (ac < 2)
		exit (0);
	nums = str_sep(ac - 1, av + 1, " ");
	while (nums[i])
	{
		if (ft_isdigit(nums[i]) == 0 && nums[i] != ' ' && nums[i] != '-')
		{
			free (nums);
			print_error(1);
			exit (0);
		}
		i++;
	}
	return (nums);
}

int	check_and_error(int *numbers)
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
				print_error(3);
				free(numbers);
				return (0);
			}
			x++;
		}
		i++;
	}
	return (1);
}
