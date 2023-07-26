#include "cub3d.h"

// void    mouv_weapon(t_main *main)
// {
//     static int step;

//     if (main->key.W || main->key.S)
//     {
//         if (main->sprite.img->instances[0].x > 950)
//             step = 0;
//         if (main->sprite.img->instances[0].x < 750)
//             step = 1;
//         if (step == 1)
//             main->sprite.img->instances[0].x += 5;
//         if (step == 0)
//             main->sprite.img->instances[0].x -= 5;
//     }
//     else
//     {
//         main->sprite.img->instances[0].x = 850;
//         main->sprite.img->instances[0].y = 598;
//     }
// }