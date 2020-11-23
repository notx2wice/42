/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:49:46 by ukim              #+#    #+#             */
/*   Updated: 2020/10/23 16:45:25 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*mk_null_str(char *ans)
{
	if (!(ans = (char*)malloc(sizeof(char))))
		return (NULL);
	ans[0] = '\0';
	return (ans);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s;
	char		*dest;
	char		*ans;

	ans = NULL;
	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen(s1);
	if (size_s == 0)
		return (mk_null_str(ans));
	size_s--;
	while (size_s && ft_strchr(set, s1[size_s]))
		size_s--;
	dest = ft_substr((char*)s1, 0, size_s + 1);
	if (!dest)
		return (mk_null_str(ans));
	return (dest);
}
