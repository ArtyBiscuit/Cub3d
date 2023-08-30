/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:20:58 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/30 14:31:57 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/***************  INCLUDES  ****************/

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../lib/minilibx/include/MLX42/MLX42.h"
# include "../lib/minilibx/include/MLX42/MLX42_Int.h"
# include "../lib/libft/libft.h"
# include "cub3d_struct.h"

/***************  DEFINES  ****************/

# define WIDTH 1280
# define HEIGHT 720
# define MINIMAP_SIZE 80
# define PI 3.14159265359
# define MLX_ERROR 1
# define MAP_NF 202
# define NO 1
# define SO 2
# define WE 3
# define EA 4

/***************  FUNCTIONS  ****************/

//	src/collider
int			check_collider_x(t_main *main, float pos_x, float pos_y);
int			check_collider_y(t_main *main, float pos_x, float pos_y);
//	src/hook
void		key_hook(mlx_key_data_t keydata, void *param);
void		loop_hook(void *param);
//	src/hook/key
void		key_action_press(mlx_key_data_t keydata, t_key *key);
void		key_action_release(mlx_key_data_t keydata, t_key *key);
void		key_applied(t_main *main);
//	src/hook/movement
void		player_movement_forward(t_main *main, float speed);
void		player_movement_left(t_main *main, float speed);
void		player_movement_back(t_main *main, float speed);
void		player_movement_right(t_main *main, float speed);
//	src/init
int			init_values(t_main *main, char *file_path);
//	src/loader/map/parsing
int			parsing_arguments(t_map *map, char **tab_file);
void		check_arguments(int argc, char **argv);
int			check_arg_format(char *arg);
void		set_player_dir(t_main *main, char c);
int 		set_player_pos(t_player *player, int i, int j);
char		**reformatting_map(char **template);
int			map_len(char **tab_file, int i);
char		*refile_new_line(char **template, int max_len, int i);
int			parsing_map(t_main *main, char **tab_file, int index);
int			parsing_map_arg(t_main *main, char *file);
int			is_space(char c);
int			is_upper_case(char c);
int			check_arg_are_refile(t_map map);
//	src/loader/texture
void		load_wall_texture(t_main *main);
//	src/raycasting
void		check_infinite_value(t_ray *ray);
void		get_ray_side(t_player player, t_ray *curent_ray);
void		perform_dda(char **map, t_ray *ray);
void		algo(t_main *main, t_ray *ray_array);
//	src/raycasting/fisheye
float		get_ray_min_dist(t_ray ray);
//	src/renderer/fog
int			set_wall_fog(int hex_color, float dist, int fog_color);
int			set_back_fog(int hex_color, float dist, int fog_color);
//	src/renderer/player
void		player_rotate(t_main *main, float theta);
void		crosshair(t_main *main);
//	src/renderer/wall
void		draw_wall_line(t_main *main, t_wall_line *line);
void		draw_wall(t_main *main, t_ray *ray_array);
double		get_line_gap(t_texture *texture, t_ray *ray, t_main *main);
t_texture	*get_wall_texture(t_main *main, t_ray *ray);
//	src/renderer
void		draw_ceiling(t_main *main, int color);
void		draw_floor(t_main *main, int color);
void		render(t_main *main, t_ray *ray_array);
//	src/utils
float		rad_converter(float radian);
float		deg_converter(float degree);
int			get_map_size_x(char **map);
int			get_map_size_y(char **map);
t_texture	*img_to_struct(mlx_image_t *img);
int			rgba_to_hex(int r, int g, int b, int a);
//	src/utils/coordinates
int			get_cardinal_side(t_ray *ray);
//	src/utils/free
void		free_all(t_main *main);
void		free_tab(char **tab);

#endif
