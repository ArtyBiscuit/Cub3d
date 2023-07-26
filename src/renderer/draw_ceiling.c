#include "../../inc/cub3d.h"

static int set_fog_ceiling(unsigned int hex_color, float dist, unsigned int fog_color)
{
    int red;
    int green;
    int blue;

    red = (hex_color >> 24) & fog_color;
    green = (hex_color >> 16) & fog_color;
    blue = (hex_color >> 8) & fog_color;

    red = red * (dist);
    green = green * (dist);
    blue = blue * (dist);

    printf("dist: %f\n", dist);
    return (rgba_to_hex(red, green, blue, 255));
}

void    draw_ceiling(t_main *main, unsigned int color)
{
    int i;
    int j;
    int gradientColor;
    int relative_i;

 
    i = 0;
    while (i < (HEIGHT))
    {
        relative_i = i - main->player.view;
        if (relative_i <= 1)
            gradientColor = color;
        else if (relative_i >= (HEIGHT / 2))
            gradientColor = color;
        else
            gradientColor = set_fog_ceiling(color, ((float)-relative_i / (HEIGHT / 2.0)), 0xFF);
        j = 0;
        while(j < WIDTH)
        {
            if (i < HEIGHT)
                mlx_put_pixel(main->mlx_data.img, j, i, gradientColor);
            j++;
        }
        i++;
    }  
}