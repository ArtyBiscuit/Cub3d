#include "cub3d.h"

void    load_sprite(t_main *main)
{
    main->sprite.texture = mlx_load_png("src/texture/AWP.png");
    main->sprite.img = mlx_texture_to_image(main->mlx_data.mlx, main->sprite.texture);
    mlx_image_to_window(main->mlx_data.mlx, main->sprite.img, 10, 10);
}