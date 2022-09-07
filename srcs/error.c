/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 22:52:25 by aball             #+#    #+#             */
/*   Updated: 2022/09/07 22:11:07 by aball            ###   ########.fr       */
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

int	char_to_int(char *str, char **nums, int *numbers)
{
	int		s;
	long	r;

	r = 0;
	s = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		r *= 10;
		r += *str - '0';
		str++;
		if (r * s > INT_MAX || (r * s) < INT_MIN)
		{
			write(2, "Error\n", 6);
			free_double(nums, 0);
			free(numbers);
			exit (0);
		}
	}
	return (r * s);
}

int	*check_duplicates(char **nums, int size)
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
		numbers[i] = char_to_int(nums[i], nums, numbers);
		i++;
	}
	if (!check_and_error(numbers, size, nums))
		free_double(nums, 1);
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
		if (ft_isdigit(nums[i]) == 0 && nums[i] != ' ' && nums[i] != '-'
			&& nums[i] != '+')
		{
			free (nums);
			print_error(1);
			exit (0);
		}
		i++;
	}
	return (nums);
}

int	check_and_error(int *numbers, int size, char **nums)
{
	int	i;
	int	x;

	i = 0;
	while (i < size)
	{
		x = i + 1;
		while (x < size)
		{
			if (numbers[i] == numbers[x])
			{
				print_error(3);
				free_double(nums, 0);
				free(numbers);
				exit (0);
			}
			x++;
		}
		i++;
	}
	return (1);
}
