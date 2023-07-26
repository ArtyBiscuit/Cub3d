#include "cub3d.h"

void	key_applied(t_main *main)
{
	float speed;

	speed = 0.1;
	if (main->key.W)
		player_movement_forward(main, speed);
	if (main->key.S)
		player_movement_back(main, speed);
	if (main->key.D)
		player_movement_right(main, speed);
	if (main->key.A)
		player_movement_left(main, speed);
	mouse(main, main->key.esc);
}