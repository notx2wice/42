/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:55:00 by ukim              #+#    #+#             */
/*   Updated: 2021/01/14 20:30:53 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define MAX_FD 1025
# define BUFFER_SIZE 100

char	*ft_gn_strdup(char *str);
char	*ft_gn_strjoin(char *s1, char *s2);
int		newline_check(char *str);
int		get_next_line(int fd, char **line);

#endif
