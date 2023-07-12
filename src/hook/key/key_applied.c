#include "cub3d.h"

void	key_applied(t_main *main)
{
	if (main->key.W)
		player_movement_forward(main);
	if (main->key.S)
		player_movement_back(main);
	if (main->key.D)
		player_movement_right(main);
	if (main->key.A)
		player_movement_left(main);
	if (main->key.view_left)
		player_rotate(main, 0.1f);
	if (main->key.view_right)
		player_rotate(main, -0.1f);
	if (main->key.view_up)
		player_view_up(main);
	if (main->key.view_down)
		player_view_down(main);
}