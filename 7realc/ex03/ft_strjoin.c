/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 18:56:35 by ukim              #+#    #+#             */
/*   Updated: 2020/08/15 14:12:10 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_length(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		str_cat(char *dest, int index, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[index + i] = src[i];
		i++;
	}
	return (index + i);
}

char	*make_blank_str(void)
{
	char *result;

	result = (char *)malloc(sizeof(char) * 1);
	result[0] = 0;
	return (result);
}

void	cat_strs(char **strs, char *sep, char *result, int size)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = str_cat(result, j, strs[i]);
		if (i < size - 1)
			j = str_cat(result, j, sep);
		i++;
	}
	result[j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		length;
	char	*result;

	if (size == 0)
	{
		result = make_blank_str();
		return (result);
	}
	length = get_length(sep) * (size - 1);
	i = 0;
	while (i < size)
		length += get_length(strs[i++]);
	result = (char *)malloc(sizeof(char) * (length + 1));
	cat_strs(strs, sep, result, size);
	return (result);
}
