/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:30:09 by notx2wice         #+#    #+#             */
/*   Updated: 2021/01/14 20:30:24 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*ft_gn_strdup(char *str)
{
	int				i;
	char			*result;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	result = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*str)
		result[i++] = *str++;
	result[i] = '\0';
	return (result);
}

char				*ft_gn_strjoin(char *s1, char *s2)
{
	int				i;
	int				j;
	char			*result;

	i = 0;
	j = 0;
	if (!s1)
	{
		if (!s2)
			return (ft_gn_strdup(""));
		return (ft_gn_strdup(s2));
	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	result = (char *)malloc(sizeof(char) * (i + j + 1));
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

int					newline_check(char *str)
{
	int				i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
