/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 15:37:14 by ukim              #+#    #+#             */
/*   Updated: 2020/11/01 19:03:45 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		something_in_st(char **st_stored, int fd)
{
	char		*tmp;
	char		*readed;
	int			ck;
	size_t		i;

	i = 0;
	if (!(readed = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (i <= BUFFER_SIZE)
		readed[i++] = 0;
	ck = read(fd, readed, BUFFER_SIZE);
	if (ck == -1)
		return (-1);
	tmp = ft_strjoin(st_stored[fd], readed);
	free(st_stored[fd]);
	free(readed);
	st_stored[fd] = tmp;
	if (ck < BUFFER_SIZE)
		return (0);
	i = ft_strlen(tmp) - BUFFER_SIZE;
	if (i > 0)
		while (i < ft_strlen(tmp))
			if (tmp[i++] == '\n')
				return (2);
	return (1);
}

static	int		nothing_in_st(char **st_stored, int fd)
{
	char		*tmp;
	int			i;
	int			ck;

	ck = 0;
	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (i <= BUFFER_SIZE)
		tmp[i++] = 0;
	ck = read(fd, tmp, BUFFER_SIZE);
	if (ck == -1)
		return (-1);
	st_stored[fd] = tmp;
	if (ck != BUFFER_SIZE)
		return (0);
	return (1);
}

static	int		fill_something(int fd, char **line, char **st_stored)
{
	int			i;

	i = nothing_in_st(st_stored, fd);
	if (i == 0)
	{
		*line = ft_strdup(st_stored[fd]);
		free(st_stored[fd]);
		st_stored[fd] = 0;
	}
	if (i == -1)
		free(st_stored[fd]);
	return (i);
}

static	int		after_work(int fd, char **line, char **st_stored, int i)
{
	char		*tmp_address;

	if (i == -1)
		return (-1);
	if (i == 2)
	{
		i = 0;
		while (st_stored[fd][i] != '\n')
			i++;
		*line = ft_substr(st_stored[fd], 0, i);
		tmp_address = ft_strdup(&st_stored[fd][i + 1]);
		free(st_stored[fd]);
		st_stored[fd] = tmp_address;
		return (1);
	}
	if (i == 0)
	{
		i = check_b_n(st_stored, fd, line);
		if (i == 1)
			return (1);
		*line = ft_substr(st_stored[fd], 0, ft_strlen(st_stored[fd]));
		free(st_stored[fd]);
		st_stored[fd] = 0;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*st_stored[MAX_FILE + 1];
	int			i;

	i = BUFFER_SIZE;
	if (fd < 0 || fd >= MAX_FILE || !line
	|| read(fd, st_stored[fd], 0) == -1 || i <= 0)
	{
		return (-1);
	}
	if (!st_stored[fd])
		if ((i = fill_something(fd, line, st_stored)) != 1)
			return (i);
	i = check_b_n(st_stored, fd, line);
	if (i)
		return (i);
	i = 1;
	while (i == 1)
		i = something_in_st(st_stored, fd);
	return (after_work(fd, line, st_stored, i));
}
