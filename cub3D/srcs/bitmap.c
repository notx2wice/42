/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukim <ukim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 17:15:34 by ukim              #+#    #+#             */
/*   Updated: 2021/01/16 02:34:08 by ukim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int			data_to_bitmap(t_img *pimg, int fd)
{
	int				i;

	i = pimg->width * pimg->height * 4 - 1;
	while (i >= 3)
	{
		write(fd, &((unsigned char *)(pimg->data))[i - 3], 1);
		write(fd, &((unsigned char *)(pimg->data))[i - 2], 1);
		write(fd, &((unsigned char *)(pimg->data))[i - 1], 1);
		write(fd, &((unsigned char *)(pimg->data))[i], 1);
		i = i - 4;
	}
	return (SUCCESS);
}

static int			mir_verti(t_img *pimg)
{
	int				line_cnt;
	unsigned int	save;
	int				e;
	int				f;

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

static int			bitmap_info_header(t_img *pimg, int fd)
{
	int				header_info_size;
	int				plane_nbr;
	int				o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &pimg->width, 4);
	write(fd, &pimg->height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &pimg->bpp, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (SUCCESS);
}

int					create_bitmap(t_img *pimg, char *name)
{
	int				fd;
	int				file_size;
	int				first_pix;

	name = ft_strjoin(name, ".bmp");
	fd = open(name, O_CREAT | O_RDWR, 0777);
	file_size = 14 + 40 + 4 + (pimg->width * pimg->height) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(pimg, fd);
	mir_verti(pimg);
	data_to_bitmap(pimg, fd);
	close(fd);
	free(name);
	return (SUCCESS);
}

void				take_screenshot(t_window *window, char *cub_path)
{
	window->save = 1;
	init_window(window, cub_path);
	raycasting(window);
	draw(window);
	create_bitmap(window->pimg, "save");
	free_window(window);
	printf("save compelete");
	exit(0);
}
