/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:53:20 by ukim              #+#    #+#             */
/*   Updated: 2021/01/14 20:30:50 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			return_line(char **stack, char **line, int check)
{
	char			*tmp_stack;
	int				i;

	if (!*stack || !**stack)
		return (0);
	tmp_stack = *stack;
	i = newline_check(tmp_stack);
	if (check == 0 && i < 0)
	{
		*line = ft_gn_strdup(*stack);
		free(*stack);
		*stack = 0;
		return (0);
	}
	tmp_stack[i] = '\0';
	*line = ft_gn_strdup(*stack);
	*stack = ft_gn_strdup(&tmp_stack[i + 1]);
	free(tmp_stack);
	if (check == 0 && !**stack)
		return (0);
	return (1);
}

static int			repeat_read(int fd, char **stack, char **line, char *buf)
{
	char			*tmp_stack;
	int				check;

	if (*stack)
		if (newline_check(*stack) >= 0)
			return (return_line(stack, line, BUFFER_SIZE + 1));
	while ((check = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[check] = '\0';
		tmp_stack = *stack;
		*stack = ft_gn_strjoin(tmp_stack, buf);
		free(tmp_stack);
		tmp_stack = NULL;
		if (newline_check(buf) >= 0)
			break ;
	}
	if (check < 0)
		return (-1);
	return (return_line(stack, line, check));
}

int					get_next_line(int fd, char **line)
{
	static char		*stack[MAX_FD];
	char			*buf;
	int				check;

	if ((fd < 0 || fd > MAX_FD) || !line
			|| BUFFER_SIZE <= 0
			|| !(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	*line = 0;
	check = repeat_read(fd, &stack[fd], line, buf);
	free(buf);
	if (check < 0)
		return (-1);
	if (check == 0 && (!stack[fd] || !*stack[fd]))
	{
		if (!*line)
			*line = ft_gn_strdup("");
		return (0);
	}
	return (check);
}
