#include "../../../inc/cub3d.h"

void sprite(t_main *main)
{
    int     color;
    float   a;
    float   b;
    float   CS;
    float   SN;
    float   sp_x;
    float   sp_y;
    float   sp_z;

    sp_x = main->sprite[0].x - main->player.pos_x;
    sp_y = main->sprite[0].y - main->player.pos_y;
    sp_z = main->sprite[0].z;

    float rota = atan2(main->player.dir_y, main->player.dir_x);
    if (rota < 0)
        rota += 2 * PI;
    CS = cos(-rota);
    SN = sin(-rota);

    a = (sp_y * CS) + (sp_x * SN);
    b = (sp_x * CS) - (sp_y * SN);

    sp_x = a;
    sp_y = b;

    sp_x = (sp_x * 600 / sp_y) + (WIDTH / 2);
    sp_z = (sp_z * 600 / sp_y) + (HEIGHT / 2) + main->player.view;

    color = rgba_to_hex(0, 247, 66, 255);
    if (sp_x > 0 && sp_x < main->mlx_data.img->width && sp_z > 0 && sp_z < main->mlx_data.img->height)
    {
        mlx_put_pixel(main->mlx_data.img, sp_x, sp_z, color);
        mlx_put_pixel(main->mlx_data.img, sp_x + 1, sp_z, color);
        mlx_put_pixel(main->mlx_data.img, sp_x, sp_z + 1, color);
        mlx_put_pixel(main->mlx_data.img, sp_x + 1, sp_z + 1, color);
        mlx_put_pixel(main->mlx_data.img, sp_x + 2, sp_z, color);
        mlx_put_pixel(main->mlx_data.img, sp_x, sp_z + 2, color);
        mlx_put_pixel(main->mlx_data.img, sp_x + 2, sp_z + 1, color);
        mlx_put_pixel(main->mlx_data.img, sp_x + 1, sp_z + 2, color);
        mlx_put_pixel(main->mlx_data.img, sp_x + 2, sp_z + 2, color);
    }
}
