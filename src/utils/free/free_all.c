#include "cub3d.h"

void    free_all(t_main *main)
{
    free_ray_array(main->ray_array);
    mlx_terminate(main->mlx_data.mlx);
}