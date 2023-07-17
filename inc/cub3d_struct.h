#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

typedef struct	s_mlx_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}				t_mlx_data;

typedef struct	s_map_data
{
	int		**format_map;
	char	**raw_map;
	int		size_x;
	int		size_y;
	char	**texture_wall;
	char	**ceiling_color;
	char	**floor_color;
}				t_map;

typedef struct	s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	plane_x;
	float	plane_y;	
	float	plane_ratio;
	float	view;
	float	theta;
}				t_player;

typedef struct	s_parameter
{
	int		crossshair_size;
    int		crossshair_color;
    float   sensitivity;
	float	fov;
}				t_parameter;

typedef struct	s_ray
{
	float	plane_ratio;
	float	ray_dir_x;
	float	ray_dir_y;
	float	delta_x;
	float	delta_y;
	float	dist_x;
	float	dist_y;
	int		step_x;
	int		step_y;
	int		ray_pos_x;
	int		ray_pos_y;
	int		wall_color;
	int		side;
	int		ray_id;
}				t_ray;

typedef struct	s_key
{
	int	W;
	int	A;
	int	S;
	int	D;
	int	view_left;
	int	view_right;
	int view_up;
	int	view_down;
}				t_key;

typedef struct  s_sprite
{
    int             number;
    mlx_texture_t   *texture;
    mlx_image_t     *img;
}               t_sprite;


typedef struct	s_main
{
	t_mlx_data	mlx_data;
	t_map		map_data;
	t_parameter	parameter;
	t_key		key;
	t_player	player;
	t_ray		*ray_array;
    t_sprite    sprite;
	float		frame_curent_time;
	float		frame_old_time;
}				t_main;
#endif