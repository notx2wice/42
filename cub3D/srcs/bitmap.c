/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@42SEOUL.KR>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 17:15:34 by ukim              #+#    #+#             */
/*   Updated: 2021/01/02 13:02:12 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	data_to_bitmap(
	t_image *pimg,
	int fd
)
{
	int i;

	i = pimg->width * pimg->height - 1;
	while (i >= 0)
	{
		write(fd, &pimg->data[i * pimg->bpp / 8], 4);
		i--;
	}
	return (SUCCES);
}

static void	mir_verti_pixel(
	t_image *pimg,
	int line_cnt,
	int *e,
	int f
)
{
	char	save;
	int		k;

	k = 3;
	while (k >= 0)
	{
		save = pimg->data[*e + (line_cnt * pimg->line_length)];
		pimg->data[*e + (line_cnt * pimg->line_length)] =
			pimg->data[f - k + (line_cnt * pimg->line_length - 1)];
		pimg->data[f - k + (line_cnt * pimg->line_length - 1)] =
			save;
		k--;
		*e = *e + 1;
	}
}

static int	mir_verti(
	t_image *pimg
)
{
	int		line_cnt;
	int		e;
	int		f;

	line_cnt = 0;
	while (line_cnt < pimg->height)
	{
		e = 0;
		f = pimg->line_length;
		while (e < f && e != f)
		{
			mir_verti_pixel(pimg, line_cnt, &e, f);
			f -= 4;
		}
		line_cnt++;
	}
	return (SUCCES);
}

static int	bitmap_info_header(
	t_image *pimg,
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
	return (SUCCES);
}

int			create_bitmap(
	t_image *pimg,
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
	return (SUCCES);
}
