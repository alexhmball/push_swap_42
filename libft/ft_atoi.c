/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:33:49 by aball             #+#    #+#             */
/*   Updated: 2022/06/17 19:15:41 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function that converts a string to an integer
int	ft_atoi(const char *str)
{
	int	s;
	int	r;

	r = 0;
	s = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s *= -1;
		str++;
		break ;
	}
	while (*str >= '0' && *str <= '9')
	{
		r *= 10;
		r += *str - '0';
		str++;
	}
	return (r * s);
}
