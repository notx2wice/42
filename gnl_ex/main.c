/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 16:05:34 by jaleman           #+#    #+#             */
/*   Updated: 2020/10/30 19:16:07 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	int fd1;
	int ret;
	int line;
	char *buff;
// buff  한줄읽은 값이 들어올 공간.
	line = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		ret = get_next_line(fd, &buff);
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		ret = get_next_line(fd, &buff);
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		close(fd);
	}
	if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd1 = open(argv[2],O_RDONLY);
		printf("fd :  %d   fd1 :  %d" , fd, fd1);
		while ((ret = get_next_line(fd, &buff)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
			free(buff);
		}
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (ret == -1)
			printf("-----------\nError\n");
		else if (ret == 0)
			printf("-----------\nEnd of file\n");
		ret = get_next_line(fd, &buff);
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		ret = get_next_line(fd, &buff);
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		close(fd);
	}
	return (0);
}
