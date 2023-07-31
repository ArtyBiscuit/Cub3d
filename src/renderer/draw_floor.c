#include "../../inc/cub3d.h"

void    draw_floor(t_main *main, int color)
{
    int i;
    int j;
    int k;
    int new_color;

    i = (HEIGHT / 2) + main->player.view;
    k = 0;
    while (i < HEIGHT)
    {
        new_color = set_back_fog(color, k, 0xFF);
        j = 0;
        while(j < WIDTH)
        {
            if(i < HEIGHT && i >= 0)
                mlx_put_pixel(main->mlx_data.img, j, i, new_color);
            j++;
        }
        if (k > -400)
            k--;
        i++;
    }
}