/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:50:57 by ukim              #+#    #+#             */
/*   Updated: 2020/11/01 19:54:38 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_b_n(char **st_stored, int fd, char **line)
{
	int			i;
	char		*tmp_address;

	i = 0;
	while (st_stored[fd][i] != '\n' && st_stored[fd][i])
		i++;
	if (st_stored[fd][i] == '\n')
	{
		tmp_address = 0;
		*line = ft_substr(st_stored[fd], 0, i);
		tmp_address = ft_strdup(&st_stored[fd][i + 1]);
		free(st_stored[fd]);
		st_stored[fd] = tmp_address;
		return (1);
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		len;
	int		i;

	len = ft_strlen(s1);
	if (!(s2 = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i += 1;
	}
	s2[i] = '\0';
	return (s2);
}

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
