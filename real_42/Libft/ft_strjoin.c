/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:50:05 by ukim              #+#    #+#             */
/*   Updated: 2020/10/04 20:10:08 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*str;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		str = (char*)malloc(sizeof(char) * (s1_len + s2_len + 1));
		if (str == NULL)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[s1_len] = s2[i];
			s1_len++;
		}
		str[s1_len] = '\0';
		return (str);
	}
	return (NULL);
}
