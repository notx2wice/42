/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:29:02 by ukim              #+#    #+#             */
/*   Updated: 2021/01/26 00:14:31 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string.h>
# include "libasm.h"
# include <stdio.h>
void test_ft_strlen(char *str)
{
	printf("test_ft_strlen\n\n");
	printf("%-10s: \"%s\"\n", "str", "");
	printf("%-10s: %zu\n", "strlen", strlen(""));
	printf("%-10s: %zu\n", "ft_strlen", ft_strlen(""));
	printf("\n");
	printf("%-10s: \"%s\"\n", "str", str);
	printf("%-10s: %zu\n", "strlen", strlen(str));
	printf("%-10s: %zu\n", "ft_strlen", ft_strlen(str));
	printf("\n");
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void test_ft_strcpy(char *str)
{
	char buffer[30];

	printf("test_ft_strcpy\n\n");
	printf("%-10s: \"%s\"\n", "str", "");
	printf("%-10s: buffer[30]\n", "copy to");
	printf("%-10s: \"%s\"\n", "strcpy", strcpy(buffer, ""));
	clear_buffer(buffer, 30);
	printf("%-10s: \"%s\"\n", "ft_strcpy", ft_strcpy(buffer, ""));
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-10s: \"%s\"\n", "str", str);
	printf("%-10s: buffer[30]\n", "copy to");
	printf("%-10s: \"%s\"\n", "strcpy", strcpy(buffer, str));
	clear_buffer(buffer, 30);
	printf("%-10s: \"%s\"\n", "ft_strcpy", ft_strcpy(buffer, str));
	clear_buffer(buffer, 30);
	printf("\n");
}

void test_ft_strcmp(char *str, char *str2)
{
	printf("test_ft_strcmp\n\n");
	printf("\n");
	printf("%-10s: \"%s\"\n", "str", str);
	printf("%-10s: \"%s\"\n", "str2", str2);
	printf("%-10s: \"%d\"\n", "strcmp", strcmp(str, str2));
	printf("%-10s: \"%d\"\n", "ft_strcmp", ft_strcmp(str, str2));
	printf("\n");
}

void test_ft_write(char *str)
{
	printf("test_ft_write\n\n");
	printf("%-10s: \"%s\"\n", "str", str);
	printf("write's print\n");
	printf("\n%-10s: \"write:%zu\"\n", "write", write(1, str, 7));
	printf("ft_write's print\n");
	printf("\n%-10s: \"ft_write:%zu\"\n", "ft_write", ft_write(1, str, 7));
	printf("\n");
	printf("%-10s: \"%s\"\n", "str", "");
	printf("%-10s: \"write:%zu\"\n", "write", write(1, "", 0));
	printf("%-10s: \"ft_write:%zu\"\n", "ft_write", ft_write(1, "", 0));
	printf("\n");
	printf("%-10s: \"%s\"\n", "str", str);
	printf("%-10s: \"write:%zu\"\n", "write", write(1, NULL, 7));
	printf("%-10s: \"ft_write:%zu\"\n", "ft_write", ft_write(1, NULL, 7));
}

void test_ft_read()
{
	int fd = open("uguikim", O_RDONLY);
	char buff1[891];
	int ret = 1;
	printf("test_ft_read\n\n");
	printf("%-10s: \n", "uguikim's profile | read ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("uguikim", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-10s: \n", "uguikim's profile | ft_read ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("test", O_RDONLY);
	printf("%-10s: \n", "file test | read ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("test", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-10s: \n", "file test | ft_read ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("wrong", O_RDONLY);
	printf("%-10s: \n", "wrong | read ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-10s: \n", "wrong | ft_read ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
}

void test_ft_strdup(char *str)
{

	char *save;
	char *save2;

	printf("test_ft_strdup\n\n");
	printf("%-10s: \"%s\"\n", "str", str);
	save = strdup(str);
	printf("%-10s: \"%s\"\n", "strdup", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(str);
	printf("%-10s: \"%s\"\n", "ft_strdup", save2);
	free(save2);
	save2 = NULL;
	printf("\n");
}

int main()
{
	test_ft_strlen("uguikim");
	test_ft_strcpy("uguikim");
	test_ft_strcmp("uguikim", "uguikim");
	test_ft_strdup("uguikim");
	test_ft_write("uguikim");
	test_ft_read();
}
