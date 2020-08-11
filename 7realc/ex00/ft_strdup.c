/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 16:16:07 by ukim              #+#    #+#             */
/*   Updated: 2020/08/08 16:20:34 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*result;
	int		index;

	index = 0;
	while (src[index])
	{
		index++;
	}
	result = (char*)malloc(sizeof(char) * index);
	index = 0;
	while (src[index])
	{
		result[index] = src[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
