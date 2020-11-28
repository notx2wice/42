/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 15:18:48 by ukim              #+#    #+#             */
/*   Updated: 2020/11/28 11:35:10 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*return_str(char *s1, char *s2, int len)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		len;

	if (!s1 || !s2)
	{
		if (!s1)
			return (ft_strdup(s2));
		return (ft_strdup(s1));
	}
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = return_str(s1, s2, len);
	return (result);
}
