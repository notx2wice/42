/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:49:52 by ukim              #+#    #+#             */
/*   Updated: 2020/10/04 22:40:22 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	int		i;

	if (ft_strlen(s) < start)
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
/*
** 문자열 s의 start 번째부터 len 개를 새로운 문자열에 할당
** 한후 리턴s
** int main()
** {
** 	char *ans = ft_substr("012dfs",0,5);
** 	printf("%s\n", ans);
** }
*/
