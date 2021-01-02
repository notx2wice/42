/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 17:15:34 by ukim              #+#    #+#             */
/*   Updated: 2021/01/02 22:45:56 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	data_to_bitmap(
	t_img *pimg,
	int fd
)
{
	int i;

	i = pimg->width * pimg->height * 4 - 1;
	while (i >= 3)
	{
		write(fd, &((unsigned char*)(pimg->data))[i-3], 1);
		write(fd, &((unsigned char*)(pimg->data))[i-2], 1);
		write(fd, &((unsigned char*)(pimg->data))[i-1], 1);
		write(fd, &((unsigned char*)(pimg->data))[i], 1);
		i = i - 4;
	}
	return (SUCCESS);
}

static int	mir_verti(
	t_img *pimg
)
{
	int		line_cnt;
	unsigned int	save;
	int		e;
	int		f;

	line_cnt = 0;
	while (line_cnt < pimg->height)
	{
		e = -1;
		f = pimg->width;
		while (++e < f)
		{
			save = pimg->data[e + (line_cnt * pimg->width)];
			pimg->data[e + (line_cnt * pimg->width)] = \
				pimg->data[f + (line_cnt * pimg->width - 1)];
			pimg->data[f + (line_cnt * pimg->width - 1)] = save;
			f--;
		}
		line_cnt++;
	}
	return (SUCCESS);
}

static int	bitmap_info_header(
	t_img *pimg,
	int fd
)
{
	int header_info_size;
	int plane_nbr;
	int o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4); //정보헤더 크기 40
	write(fd, &pimg->width, 4); //이미지 가로
	write(fd, &pimg->height, 4);//세로
	write(fd, &plane_nbr, 2); // 생상판의 수 항상 1
	write(fd, &pimg->bpp, 2); //픽셀하나를 표현하는 수
	o_count = 0;
	//not used 압축방식(4),
	while (o_count < 28) //사용되지 않는 공간
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (SUCCESS);
}

int			create_bitmap(
	t_img *pimg,
	char *name
)
{
	int fd;
	int file_size;
	int first_pix;

	name = ft_strjoin(name, ".bmp");
	fd = open(name, O_CREAT | O_RDWR);
	// 14 = 비트맵 파일 헤더 크기 40 = 비트맵 정보 헤더 크기 4 = color palette
	// 파 초 빨 reserveded순으로 저장
	file_size = 14 + 40 + 4 + (pimg->width * pimg->height) * 4;
	first_pix = 14 + 40 + 4;
	//비트맵 파일 헤더 시작
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4); //사용되지 않는 4바이트
	write(fd, &first_pix, 4); //비트맵 데이터 시작위치
	bitmap_info_header(pimg, fd);
	mir_verti(pimg);
	data_to_bitmap(pimg, fd);
	close(fd);
	free(name);
	return (SUCCESS);
}

void		take_screenshot(t_window *window, char *cub_path)
{
	window->save = 1;
	init_window(window, cub_path);
	raycasting(window);
	draw(window);
	create_bitmap(window->pimg,	"save");
	free_window(window);
	printf("save compelete");
	exit(0);
}