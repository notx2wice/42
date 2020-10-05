/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:49:46 by ukim              #+#    #+#             */
/*   Updated: 2020/10/04 22:43:38 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		size_s;
	char		*dest;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size_s = ft_strlen(s1);
	size_s--;
	while (size_s && ft_strchr(set, s1[size_s]))
		size_s--;
	dest = ft_substr((char*)s1, 0, size_s + 1);
	return (dest);
}

/*
** 시작과 끝에 있는 set의 문자를 제거 한다.
** char const *s1  (*s1) 이 상수라는 의미 s1에 든 값을
** 변경 할수 없다. 그래서 s1자체는 변경 가능 .
** int main()
** {
** 	char *test = "!@#hello!@#!@";
** 	char *ans = ft_strtrim(test, "!@#");
** 	printf("%s\n", ans);
** }
*/
