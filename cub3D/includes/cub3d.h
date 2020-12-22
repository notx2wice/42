/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekim <ekim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 20:59:59 by ekim              #+#    #+#             */
/*   Updated: 2020/12/14 20:59:59 by ekim             ###   ########.fr       */
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

// define keycode
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

//0북 1남 2서 3동
# define NO_IDX 0
# define SO_IDX 1
# define WE_IDX 2
# define EA_IDX 3
# define SPRITE_IDX 4


# define ERROR 0
# define SUCCESS 1
# define ERROR_MSG "ERROR\n"
# define MEMORY_ALLOC_ERROR "Memory allocation failed"
# define MAP_ERROR "Map is not valid"
# define RGB_ERROR "RGB is not valid"
# define PATH_ERROR "Path is not valid"
# define ARGUMENT_ERROR "Invalid argument(s) is(are) in cub file"
# define OPEN_ERROR "Failed to open file"

typedef struct			s_img
{
	void				*img;
	char				*data;
	int					bpp;
	int					line_length;
	int					endian;
	int					width;
	int					height;
}						t_img;

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
}						t_player;

typedef struct			s_sprites
{
	int					x;
	int					y;
	double				distance;
}						t_sprites;

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
	t_coord_d			rayDir;
	t_coord_d			sideDist;
	t_coord_d			deltaDist;
	double				perpwallDist;
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
	t_img				pimg;
	t_img				*img[5];
	int					*textures[5];
	t_ray				*ray;
	t_player			*player;
	t_cub				*cub;
	t_sprites			**sprite;
	int					**buffer;
	double				moveSpeed;
	double				rotSpeed;
}						t_window;


// libft functions
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s1);
char					**ft_split(const char *s, char c);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_atoi(char *str);
int						ft_isdigit(int c);
char					*ft_strchr(const char *str, int c);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *str, int fd);

// getnextline functions
int						get_next_line(int fd, char **line);

//cub3d utils
char					*ft_free_strjoin(char *s1, char *s2);
void					exit_program(char *str);
void					free_char_array(char **str);
void					free_cub(t_cub *cub);
void					free_window(t_window *window);

//map_parsing fucntions
char					**read_map_file_to_array(int fd);
void					set_cub_textures_path(char **tmp, t_cub *cub);
void					set_cub_backgrounds(char **tmp, t_cub *cub);
int						*fill_one_line_worldmap(char *line, t_window *window, int idx, int *pos_cnt);
void					make_worldmap(char **line, t_window *window);
void					set_cub_worldmap(char **line, t_window *window);
int						check_player_direction(t_cub *cub);
int						set_cub(t_window *window, char *path);

//player
void					set_player_dir_plane_coord(t_window *window);
void					set_player(t_cub *cub);

//init
void					init_cub(t_cub *cub);
void					init_player(t_player *player);
void					init_coord_d(t_coord_d coord_d);
void					init_coord_i(t_coord_i coord_i);
void					init_ray(t_ray *ray);
void					init_img(t_img *img);
void					init_window(t_window *window, char *path);

//ray
int						raycasting(t_window *window);

//move
void					rotate_player(t_player *player, int rotSpeed, int keycode);
void					move_player_forward(t_player *player, t_cub *cub, int moveSpeed);
void					move_player_left(t_player *player, t_cub *cub, int moveSpeed);
void					move_player_backward(t_player *player, t_cub *cub, int moveSpeed);
void					move_player_right(t_player *player, t_cub *cub, int moveSpeed);

//textures
int						*loadImage(t_window *window, char *path, t_img *img);
void					load_texture(t_window *window);
void					floor_ceiling_to_buffer(t_window *window);
void					wall_to_buffer(t_window *window, t_ray *ray, int x);

#endif
