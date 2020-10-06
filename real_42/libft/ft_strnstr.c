/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 00:34:02 by ukim              #+#    #+#             */
/*   Updated: 2020/10/04 01:30:03 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int pos;
	unsigned int i;

	if (!*to_find)
		return ((char*)str);
	pos = 0;
	while (str[pos] != '\0' && (size_t)pos < len)
	{
		if (str[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && str[pos + i] == to_find[i] &&
					(size_t)(pos + i) < len)
				++i;
			if (to_find[i] == '\0')
				return ((char*)&str[pos]);
		}
		++pos;
	}
	return (0);
}
/*
** char *strnstr(const char *str, const char *to_find, size_t len);
** 이 함수는 str 문자열에 len 길이 중에서 to_find 문자열을 찾는 것이다.
**
** 반환 값
** 만약 to_find 값이 비어 있으면 str를 반환한다.
** str 문자열에서 to_find 문자열을 찾지 못하면 NULL을 반환한다.
** to_find 문자열을 찾으면 str에 to_find 문자열 시작 부분 위치 주소를 반환한다.
*/
