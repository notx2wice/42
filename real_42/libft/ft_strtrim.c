/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:49:46 by ukim              #+#    #+#             */
/*   Updated: 2020/10/08 20:09:05 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s;
	char		*dest;
	char		*ans;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen(s1);
	size_s--;
	while (size_s && ft_strchr(set, s1[size_s]))
		size_s--;
	dest = ft_substr((char*)s1, 0, size_s + 1);
	if (!dest)
	{
		if (!(ans = (char*)malloc(sizeof(char))))
			return (NULL);
		ans[0] = '\0';
		return (ans);
	}
	return (dest);
}
