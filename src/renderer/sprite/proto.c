#include "../../../inc/cub3d.h"

void sprit(t_main *main ,t_texture *sprite, float x, float y)
{
    float sprite_dist;
    float sprite_x;
    float sprite_y;

    sprite_dist = ((main->player.pos_x - x) * (main->player.pos_x - x) + (main->player.pos_y - y) * (main->player.pos_y - y));
    sprite_x = x - main->player.pos_x;
    sprite_y = y - main->player.pos_y;

    // calcule la hauteur du sprite à l'écran
    int spriteHeight = abs((int)(HEIGHT / (sprite_dist))); //l'utilisation de 'transformY' au lieu de la distance réelle empêche le fisheye
    //calcule le pixel le plus bas et le plus haut pour remplir la bande actuelle
    int drawStartY = -spriteHeight / 2 + HEIGHT / 2;
    if(drawStartY < 0) drawStartY = 0 ;
    int drawEndY = spriteHeight / 2 + HEIGHT / 2;
    if(drawEndY >= HEIGHT) drawEndY = HEIGHT - 1;

    // calcule la largeur du sprite
    int spriteWidth = abs((int)(WIDTH / (sprite_dist)));
    int drawStartX = -spriteWidth / 2;
    if(drawStartX < 0) drawStartX = 0 ;
    int drawEndX = spriteWidth / 2;
    if(drawEndX >= WIDTH) drawEndX = WIDTH - 1;

    int color;
    for (int i = drawStartY; i < drawEndY; i++)
    {
        for (int j = drawStartX; j < drawEndX; j++)
        {
             color = sprite->pixels[j + i * sprite->size_x];
             mlx_put_pixel(main->mlx_data.mlx, i, j, color);
        }
    }
}