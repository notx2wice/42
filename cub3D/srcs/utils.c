/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 19:28:47 by ekim              #+#    #+#             */
/*   Updated: 2020/12/15 19:28:47 by ekim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char		*ft_free_strjoin(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin((const char*)s1, (const char*)s2);
	free(s1);
	free(s2);
	return (result);
}

void		exit_program(char *str)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(str, 1);
	ft_putchar_fd('\n', 1);
	exit(EXIT_FAILURE);
}

void		free_array(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

static void	free_buffer_img_sprite_cub(t_window *window)
{
	int		i;

	i = 0;
	while (i < window->cub->res_height)
		free(window->buffer[i++]);
	free(window->buffer);
	i = 0;
	while (i < 5)
		mlx_destroy_image(window->mlx, window->img[i++]->img);
	mlx_destroy_image(window->mlx, window->pimg->img);
	free(window->pimg);
	free(window->img);
	i = 0;
	while (i < window->cub->sprite_cnt)
		free(window->sprites[i++]);
	free(window->sprites);
	free(window->d_sprites);
	free(window->cub->ea_path);
	free(window->cub->we_path);
	free(window->cub->so_path);
	free(window->cub->no_path);
	free(window->cub->sprite_path);
	free_array(window->cub->worldmap);
}

void		free_window(t_window *window)
{
	free(window->ray->z_buffer);
	free(window->ray);
	free(window->player);
	free_buffer_img_sprite_cub(window);
	free(window->cub);
	free(window->key);
	free(window);
}