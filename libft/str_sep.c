/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_sep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aball <aball@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 23:54:08 by aball             #+#    #+#             */
/*   Updated: 2022/06/24 14:08:17 by aball            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int str_len(char *str)
{
	int j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

int dest_len(char **strs, int size, char *sep)
{
	int i;
	int sep_len;
	int dest_len;

	i = 0;
	dest_len = 0;
	sep_len = str_len(sep);
	while (i < size)
	{
		dest_len += str_len(strs[i]);
		dest_len += sep_len;
		i++;
	}
	dest_len -= sep_len;
	return (dest_len);
}

// concatenate all the strings pointed by strs separated by sep, size is the number of strs
char *str_sep(int size, char **strs, char *sep)
{
	char *dest;
	int i;
	int j;
	int x;
	int final_len;

	i = 0;
	x = 0;
	final_len = dest_len(strs, size, sep);
	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	dest = (char *)malloc((final_len + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[x++] = strs[i][j++];
		j = 0;
		while (sep[j] && i != size - 1)
			dest[x++] = sep[j++];
		i++;
	}
	dest[x] = '\0';
	return (dest);
}