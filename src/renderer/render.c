/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:53:00 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/01 14:53:09 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void sprit(t_main *main ,t_texture *sprite, float x, float y)
// {
//     float sprite_dist;
//     float sprite_x;
//     float sprite_y;

//     (void)sprite;
//         sprite_dist = ((main->player.pos_x - x) * (main->player.pos_x - x) + (main->player.pos_y - y) * (main->player.pos_y - y));
//         sprite_x = x - main->player.pos_x;
//         sprite_y = y - main->player.pos_y;

//         // calcule la hauteur du sprite à l'écran
//         int spriteHeight = abs((int)(HEIGHT / (sprite_dist))); //l'utilisation de 'transformY' au lieu de la distance réelle empêche le fisheye
//         //calcule le pixel le plus bas et le plus haut pour remplir la bande actuelle
//         int drawStartY = -spriteHeight / 2 + HEIGHT / 2;
//         if(drawStartY < 0) drawStartY = 0 ;
//         int drawEndY = spriteHeight / 2 + HEIGHT / 2;
//         if(drawEndY >= HEIGHT) drawEndY = HEIGHT - 1;

//         // calcule la largeur du sprite
//         int spriteWidth = abs((int)(WIDTH / (sprite_dist)));
//         int drawStartX = -spriteWidth / 2;
//         if(drawStartX < 0) drawStartX = 0 ;
//         int drawEndX = spriteWidth / 2;
//         if(drawEndX >= WIDTH) drawEndX = WIDTH - 1;

//         int color;
//         for (int i = drawStartX; i < drawEndX; i++)
//         {
//             int texX = (int)(256 * (i - (-spriteWidth / 2 + sprite_dist)) * sprite->size_x / spriteWidth) / 256;
//             for (int j = drawStartY; j < drawEndY; j++)
//             {
//                 int d = (j) * 256 - HEIGHT * 128 + spriteHeight * 128;
//                  int texY = ((d * sprite->size_y) / spriteHeight) / 256;
//                  color = sprite->pixels[texY + texY * sprite->size_x];
//                 // printf("%d-%d\n", texX, texY);
//                  if (texY < HEIGHT && texY > 0 && texX < WIDTH && texX > 0)
//                     mlx_put_pixel(main->mlx_data.img, texY, texX, color);
//             }
//         }
// }

void    render(t_main *main, t_ray *ray_array)
{
    (void)ray_array;

    draw_ceiling(main, main->map.ceiling_color);
    draw_floor(main, main->map.floor_color);
    draw_wall(main, ray_array);
    minimap(main,100, 100, 10);
    sprite(main);
    crosshair(main);
    //mouv_weapon(main);
    //main->sprite.img->instances[0].z = 1;
}
