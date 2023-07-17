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
	mouse(main, main->key.esc);
}