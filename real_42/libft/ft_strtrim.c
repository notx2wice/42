/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 18:49:46 by ukim              #+#    #+#             */
/*   Updated: 2020/10/07 20:11:35 by ukim             ###   ########.fr       */
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
			return (0);
		ans[0] = '\0';
		return (ans);
	}
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
**	유닛테스트에서 결과 값이 없는것을 표현해야 함 그래서
**	값이 ""인경우에 값을 재할당한 후 리턴.
** }
*/
