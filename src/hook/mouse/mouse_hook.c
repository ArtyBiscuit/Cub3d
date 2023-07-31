#include "cub3d.h"

void mouse(t_main *main, int flag)
{
    int x;
    int y;
    if (flag)
    {
        mlx_set_cursor_mode(main->mlx_data.mlx, MLX_MOUSE_HIDDEN);
        mlx_get_mouse_pos(main->mlx_data.mlx, &x, &y);
        mlx_set_mouse_pos(main->mlx_data.mlx, WIDTH/2, HEIGHT/2);
        x = x - WIDTH / 2;
        y = y - HEIGHT / 2;
        main->player.view -= y * 1;
        player_rotate(main, x * 0.003);
    }
    else
        mlx_set_cursor_mode(main->mlx_data.mlx, MLX_MOUSE_NORMAL);
    //printf("\e[1A\e[2KX: %d,Y: %d\n", x, y);
    return ;
}
