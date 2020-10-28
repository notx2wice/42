/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:37:14 by ukim              #+#    #+#             */
/*   Updated: 2020/10/29 01:01:18 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		something_in_st()
{
	// end == 0  fail == -1 normal == 1
}

static	int		nothing_in_st()
{
	// end == 0  fail == -1 normal == 1
}

int				get_next_line(int fd, char **line)
{
	static char *st_stored[MAX_FILE];
	char		*tmp_buff;
	char		*tmp_address;
	size_t		i;

	i = 0;
	if (fd < 0 || fd > MAX_FILE || !line || !read(fd, st_stored[fd], 0)
		|| !(tmp_buff = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (!st_stored[fd])
	{
		i = nothing_in_st();
		if (i == 0)
		{
			*line = ft_strdup(&st_stored[fd][i]);
			free(st_stored[fd]);
			st_stored[fd] = NULL;
			return (0);
		}
		else if (i == 0)
			return (-1);
	}
	while (st_stored[fd][i] == '\n' || st_stored[fd][i])
		i++;
	if (st_stored[fd][i] == '\n')
	{
		*line = ft_substr(st_stored[fd], 0, i - 1);
		tmp_address = ft_strdup(&st_stored[fd][i]);
		free(st_stored[fd]);
		st_stored[fd] = tmp_address;
		return (1);
	}
	sothing_in_st(i);
	return (1);
}
