/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 09:34:23 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/07 15:20:46 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void sprite(t_main *main)
{
    int     color;
    float   a;
    float   b;
    float   sp_x;
    float   sp_y;
    float   sp_z;

    sp_x = main->sprite[0].x - main->player.pos_x;
    sp_y = main->sprite[0].y - main->player.pos_y;
    sp_z = main->sprite[0].z;

    float rota = atan2(main->player.dir_y, main->player.dir_x);
    if (rota < 0)
        rota += 2 * PI;

    a = (sp_y * cos(-rota)) + (sp_x * sin(-rota));
    b = (sp_x * cos(-rota)) - (sp_y * sin(-rota));

    sp_x = a;
    sp_y = b;

    sp_x = (sp_x * 800.0 / sp_y) + (WIDTH / 2);
    sp_z = (-sp_z * 800.0 / sp_y) + (HEIGHT / 2) + main->player.view;

    if (sp_x > 0 && sp_x < main->mlx_data.img->width && sp_z > 0 && sp_z < main->mlx_data.img->height)
    {
        for (int i = 64; i != 0; i--)
        {
            for(int j = 0; j != 64; j++)
            {
                color = main->sprite->texture->pixels[i + j * main->sprite->texture->size_y];
                mlx_put_pixel(main->mlx_data.img, sp_x, sp_z, color);
                // sp_z--;
            }
            sp_x++;
        }
    }
}
