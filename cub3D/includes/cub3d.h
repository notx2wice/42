/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kim-eunju <kim-eunju@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:59:59 by ekim              #+#    #+#             */
/*   Updated: 2021/01/10 18:45:01 by kim-eunju        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "./libft/libft.h"
# include "./getnextline/get_next_line.h"
# include <mlx.h>
# include <stdio.h>

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_RELEASED 3
# define KEY_EXIT 17

# define NO_IDX 0
# define SO_IDX 1
# define WE_IDX 2
# define EA_IDX 3
# define S_IDX 4

# define ERROR 0
# define SUCCESS 1
# define ERROR_MSG "ERROR\n"
# define MEMORY_ALLOC_ERROR "Memory allocation failed"
# define MAP_ERROR "Map is not valid"
# define PATH_ERROR "Path is not valid"
# define ARGUMENT_ERROR "Invalid argument(s) is(are) in cub file"
# define OPEN_ERROR "Failed to open file"

typedef struct			s_img
{
	void				*img;
	unsigned int		*data;
	int					bpp;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_img;

typedef struct			s_key
{
	int					forward;
	int					backward;
	int					left;
	int					right;
	int					turn_left;
	int					turn_right;
}						t_key;

typedef struct			s_coord_i
{
	int					x;
	int					y;
}						t_coord_i;

typedef struct			s_coord_d
{
	double				x;
	double				y;
}						t_coord_d;

typedef struct			s_player
{
	t_coord_d			pos;
	t_coord_d			dir;
	t_coord_d			plane;
	double				cam_height;
}						t_player;

typedef struct			s_sprite
{
	double				x;
	double				y;
	double				distance;
}						t_sprite;

typedef struct			s_d_sprites
{
	double				transform_x;
	double				transform_y;
	int					screen_x;
	int					sprite_height;
	int					draw_start_y;
	int					draw_end_y;
	int					sprite_width;
	int					draw_start_x;
	int					draw_end_x;
	int					tex_x;
}						t_d_sprites;

typedef struct			s_cub
{
	char				*ea_path;
	char				*we_path;
	char				*so_path;
	char				*no_path;
	char				*sprite_path;
	int					floor_color;
	int					ceiling_color;
	int					map_col;
	int					map_row;
	char				**worldmap;
	int					res_width;
	int					res_height;
	char				p_direction;
	int					sprite_cnt;
}						t_cub;

typedef struct			s_ray
{
	t_coord_i			map;
	t_coord_i			step;
	t_coord_d			ray_dir;
	t_coord_d			side_dist;
	t_coord_d			delta_dist;
	double				perpwall_dist;
	int					hit;
	int					side;
	int					lineheight;
	int					draw_start;
	int					draw_end;
	int					tex_num;
	int					tex_x;
	int					tex_y;
	double				wall_x;
	double				*z_buffer;
}						t_ray;

typedef struct			s_window
{
	void				*mlx;
	void				*win;
	int					save;
	t_img				*img[5];
	t_img				*pimg;
	t_ray				*ray;
	t_player			*player;
	t_cub				*cub;
	t_sprite			**sprites;
	t_key				*key;
	t_d_sprites			*d_sprites;
	int					visited_res;
	unsigned int		**buffer;
	double				move_speed;
	double				rot_speed;
}						t_window;

char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s1);
char					**ft_split(const char *s, char c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_atoi(char *str, int *i);
int						ft_isdigit(int c);
char					*ft_strchr(const char *str, int c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *str, int fd);
void					ft_bzero(void *s, size_t n);
int						get_next_line(int fd, char **line);
char					*ft_free_strjoin(char *s1, char *s2);
void					exit_program(char *str);
void					free_array(char **str);
void					free_cub(t_cub *cub);
void					free_window(t_window *window);

void					init_coord_d(t_coord_d coord_d);
void					init_player(t_player *player);
void					init_cub(t_cub *cub);
void					init_key(t_key *key);
void					init_ray(t_ray *ray);
void					init_window(t_window *window, char *path);

int						key_manager(t_window *window);
void					rotate_player(t_player *player, double	rot_spee,
	int keycode);
void					move_player_forward(t_player *player, t_cub *cub,
	double move_peed);
void					move_player_left(t_player *player, t_cub *cub,
	double move_peed);
void					move_player_backward(t_player *player, t_cub *cub,
	double move_peed);
void					move_player_right(t_player *player, t_cub *cub,
	double move_peed);

int						destroy_window(void *param);
int						key_released(int key, void *param);
int						key_press(int key, void *param);

void					set_cub_worldmap(char **line, t_window *window);
void					set_cub(t_window *window, char *path);
int						check_color_valid(char *cub_line);
int						map_size_check(t_window *window, int x, int y);
int						check_wall_valid(t_window *window);

void					load_texture(t_window *window);
void					calc_wall_texture(t_window *window, t_ray *ray);
void					floor_ceiling_to_buffer(t_window *window);
void					wall_to_buffer(t_window *window, t_ray *ray, int x);

void					set_player_dir_plane_coord(t_window *window);
void					set_ray_raydir(double camera_x, t_ray *ray,
	t_player *player);
void					find_and_calc_wall(t_ray *ray, t_cub *cub);
void					calc_perp_lineheight_draws_drawe(t_ray *ray,
	t_player *player, t_cub *cub);
void					set_ray_step_sidedist(t_ray *ray, t_coord_d *pos);
void					calc_transform_x_y(t_window *window, t_player *player,
	t_d_sprites *sprites, int idx);
void					calc_screenx_height_draw(t_window *window,
	t_d_sprites *sprites, double s_width, double s_height);
void					sprite_raycast(t_window *window, t_d_sprites *sprites);
void					do_raycasting(t_window *window);
void					draw_sprite(t_window *window);
int						raycasting(t_window *window);

int						create_bitmap(t_img *pimg, char *name);
void					take_screenshot(t_window *window, char *cub_path);
void					draw(t_window *window);

#endif
