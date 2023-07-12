#include "cub3d.h"

void    player_view_up(t_main *main)
{
    if (main->player.view + 15 < 250)
		main->player.view += 15;
}

void    player_view_down(t_main *main)
{
    if (main->player.view - 15 > -250)
		main->player.view -= 15;
}