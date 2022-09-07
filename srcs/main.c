/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 22:30:30 by aball             #+#    #+#             */
/*   Updated: 2022/09/05 21:28:40 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_negative(char **nums, int i)
{
	int	j;

	j = 0;
	while (nums[i][j])
	{
		if (j != 0 && ft_isdigit(nums[i][j]) == 0)
		{
			free_double(nums);
			print_error(1);
			exit (0);
		}
		else if (j == 0 && nums[i][j] == '-'
			&& ft_isdigit(nums[i][j + 1]) == 0)
		{
			free_double(nums);
			print_error(1);
			exit (0);
		}
		j++;
	}
}

static int	count_nums(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		check_negative(nums, i);
		i++;
	}
	return (i);
}

static t_listy	*create_list(int *nums, int ac)
{
	int		i;
	t_listy	*head;
	t_listy	*current;
	t_listy	*temp;

	i = 0;
	current = new_lst(nums[i]);
	head = current;
	lst_add_back(&head, current);
	temp = head;
	i++;
	while (i < ac)
	{
		head = temp;
		current = new_lst(nums[i]);
		lst_add_back(&head, current);
		i++;
	}
	head = temp;
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
	free (nums);
	ac = count_nums(only_nums);
	if (ac == 0)
	{
		free_double(only_nums);
		exit (0);
	}
	numbers = check_duplicates(only_nums, ac);
	free_double(only_nums);
	a = create_list(numbers, ac);
	median = find_median(numbers, ac);
	if (is_sorted_a(&a) == 0)
		sorting(&a, ac, median, numbers);
	free (numbers);
	lst_clear(&a, free);
	free (a);
	return (0);
}
