/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:49:52 by ukim              #+#    #+#             */
/*   Updated: 2020/10/21 20:25:15 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	if (!s || ft_strlen(s) < start)
	{
		dest = malloc(sizeof(char));
		*dest = '\0';
		return (dest);
	}
	dest = malloc(len * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (len > 0 && s[start])
	{
		dest[i] = s[start];
		i++;
		start++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
