/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:45:55 by ukim              #+#    #+#             */
/*   Updated: 2020/10/05 16:04:51 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			count_words(char const *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

int			words_len(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

void		*leak(char **splitted, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
	return (NULL);
}

char		**fill(char const *s, int words, char c, char **splitted)
{
	int		i;
	int		j;
	int		len;

	i = -1;
	while (++i < words)
	{
		while (*s == c)
			s++;
		len = words_len(s, c);
		if (!(splitted[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (leak(splitted, i));
		j = 0;
		while (j < len)
			splitted[i][j++] = *(s++);
		splitted[i][j] = '\0';
	}
	splitted[i] = NULL;
	return (splitted);
}

char		**ft_split(char	const *s, char c)
{
	char	**splitted;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!(splitted = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	splitted = fill(s, words, c, splitted);
	return (splitted);
}

/*
** int			 main(int ac, char **av)
** {
** 	(void) ac;
** 	char **test = ft_split(av[1],'1');
** 	int i = 0;
** 	while(test[i])
** 		printf("%s\n",test[i++]);
** 연속된 구분자를 처리하는 부분이 필요함 fill의 초반에 구현해야한다.
*/
