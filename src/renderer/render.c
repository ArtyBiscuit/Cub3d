#include "../../inc/cub3d.h"
void    render(t_main *main, t_ray *ray_array)
{
    (void)ray_array;

    draw_ceiling(main, 0xff00ffff);
    draw_floor(main, 0xff00ffff);
    draw_wall(main, ray_array);
    minimap(main,100, 100, 10);
    crosshair(main);
    //mouv_weapon(main);
    //main->sprite.img->instances[0].z = 1;
}