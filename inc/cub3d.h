#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include "../lib/minilibx/include/MLX42/MLX42.h"
# include "../lib/minilibx/include/MLX42/MLX42_Int.h"
# include "../lib/libft/libft.h"
# include "cub3d_struct.h"

# define WIDTH 1900
# define HEIGHT 1000
# define MINIMAP_SIZE 80
# define PI 3.14159265359
# define MLX_ERROR 1
# define PAR_ERROR 122

/***************  STRUCT  ****************/


/***************  FUNCTION  ****************/
//	src/collider
int		check_collider_x(t_main *main, float pos_x, float pos_y);
int		check_collider_y(t_main *main, float pos_x, float pos_y);
//	src/error/map_error
//	src/error/mlx_error
//	src/error/pars_error
//	src/hook
void	key_hook(mlx_key_data_t	keydata, void* param);
void	loop_hook(void* param);
//	src/hook/key
void    key_action_press(mlx_key_data_t keydata, t_key *key);
void    key_action_release(mlx_key_data_t keydata, t_key *key);
void	key_applied(t_main *main);
//	src/hook/movement
void    player_movement_forward(t_main *main);
void    player_movement_back(t_main *main);
void    player_movement_right(t_main *main);
void    player_movement_left(t_main *main);
void    player_view_up(t_main *main);
void    player_view_down(t_main *main);
//	src/init
int		init_values(t_main *main);
//	src/loader
//	src/loader/map
//	src/loader/textur
void    load_sprite(t_main *main);
//	src/raycasting
void	check_infinite_value(t_ray *ray);
void	get_ray_side(t_player player, t_ray *curent_ray);
void	perform_dda(int **map, t_ray *ray);
void	algo(t_main *main, t_ray *ray_array);
//	src/raycasting/fisheye
float	get_ray_min_dist(t_ray ray);
//	src/renderer
void    render(t_main *main, t_ray *ray_array);
//	src/minimap
void	minimap(t_main *main, int pos_x, int pos_y, float zoom);
//	src/renderer/wall
void	draw_wall(t_main *main, t_ray *ray_array);
void	draw_line(t_main *main, int start, int end, t_ray ray);
void	get_wall_color(int **map, t_ray *ray);
//	src/renderer/player
void	player_rotate(t_main *main, float theta);
void    crosshair(t_main *main);
//	src/utils
float	rad_converter(float radian);
float	deg_converter(float degree);
//	src/utils/free
void    free_all(t_main *main);
void    free_ray_array(t_ray *ray_array);
//	PROTOTYP-KEY [src/hook/key_hook.c]
void	map(t_main *main, t_ray *ray_array, int pos_x, int pos_y);

void	put_circle(mlx_image_t *img, int pos_x, int pos_y, int radius);
void    mouv_weapon(t_main *main);
#endif