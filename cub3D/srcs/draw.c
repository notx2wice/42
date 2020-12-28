/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 02:15:37 by kim-eunju         #+#    #+#             */
/*   Updated: 2020/12/28 20:18:46 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	    texture_on_img(t_line *line, t_img *texture, t_window *window, t_ray *ray)
{
	int     d;

	d = line->y * texture->line_length - (window->cub->res_height
		* window->player->cam_height) * texture->line_length
		/ 2 + ray->lineheight * texture->line_length / 2;
	line->tex_y = ((d * texture->height) / ray->lineheight)
		/ texture->line_length;
	window->pimg->data[line->y * window->pimg->line_length + line->x
					* window->pimg->bpp / 8] = texture->data[line->tex_y
					* texture->line_length + line->tex_x * (texture->bpp / 8)];
	window->pimg->data[line->y * window->pimg->line_length + line->x
					* window->pimg->bpp / 8 + 1] = texture->data[line->tex_y
					* texture->line_length + line->tex_x * (texture->bpp / 8)
					+ 1];
	window->pimg->data[line->y * window->pimg->line_length + line->x
					* window->pimg->bpp / 8 + 2] = texture->data[line->tex_y
					* texture->line_length + line->tex_x * (texture->bpp / 8)
					+ 2];
                    
//player's cam_height = 1.0 (basic setting)
}

void		ver_line_texture_image(t_line *line, t_window *window, t_img *texture, t_ray *ray)
{
	int     y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			texture_on_img(line, texture, window, ray);
			line->y++;
		}
	}
}

void		pixel_put_to_image(int color, int x, int y, t_img *img)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	img->data[y * img->line_length + x * img->bpp / 8] = r;
	img->data[y * img->line_length + x * img->bpp / 8 + 1] = g;
	img->data[y * img->line_length + x * img->bpp / 8 + 2] = b;
}

void		ver_line_color_image(t_line *line, t_window *window, int color)
{
	int     y;
	int     y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_put_to_image(color, line->x, y, window->pimg);
			y++;
		}
	}
}