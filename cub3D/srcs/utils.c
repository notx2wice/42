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

void		free_cub(t_cub *cub)
{
	//path free
	free(cub->ea_path);
	free(cub->we_path);
	free(cub->so_path);
	free(cub->no_path);
	free(cub->sprite_path);
	free_array(cub->worldmap);
	free(cub);
}

void		free_window(t_window *window)
{
	int		i;

	i = 0;
	//ray
	free(window->ray);
	free(window->player);
	free_cub(window->cub);
	// free(window->sprite);
	while (i < 5)
	{
		free(window->textures[i]);
		i++;
	}
	free(window);
}