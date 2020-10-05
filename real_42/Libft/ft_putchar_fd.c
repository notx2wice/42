/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42seoul.kr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 17:48:47 by ukim              #+#    #+#             */
/*   Updated: 2020/10/05 22:49:42 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
/*
** int main()
** {
** 	int fd;
** 	mode_t mode;
** 	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
** 	//소유자 읽기 권한 | 소유자 쓰기 권한 | 그룹 읽기 권한 | 기타 사용자 읽기 권한
** 	fd = open("unix.txt", O_CREAT | O_EXCL | O_RDWR, mode);
** 	printf("unix.txt : fd = %d\n", fd);
** 	if(fd == -1)
** 	{
** 		fd = open("unix.txt", O_RDWR, mode);
** 		ft_putchar_fd('a',fd);
** 		ft_putchar_fd('\n',fd);
** 	}
** 	ft_putchar_fd('a',fd);
** 	ft_putchar_fd('\n',fd);
** 	close(fd);
** 	return 0;
** }
*/
