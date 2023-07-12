#include "cub3d.h"

void    player_movement_forward(t_main *main)
{
    float	new_x;
	float	new_y;
	float	old_x;
	float	old_y;

	old_x = main->player.pos_x;
	old_y = main->player.pos_y;
   	new_x = main->player.pos_x + (0.1f * main->player.dir_x);
	new_y = main->player.pos_y + (0.1f * main->player.dir_y);
	if (check_collider_x(main, new_x, old_y))
		main->player.pos_x = new_x;
	if (check_collider_y(main, old_x, new_y))
		main->player.pos_y = new_y;
}

void    player_movement_back(t_main *main)
{
    float	new_x;
	float	new_y;
	float	old_x;
	float	old_y;

	old_x = main->player.pos_x;
	old_y = main->player.pos_y;
    new_x = main->player.pos_x - (0.1f * main->player.dir_x);
	new_y = main->player.pos_y - (0.1f * main->player.dir_y);
	if (check_collider_x(main, new_x, old_y))
		main->player.pos_x = new_x;
	if (check_collider_y(main, old_x, new_y))
		main->player.pos_y = new_y;
}

void    player_movement_right(t_main *main)
{
    float	new_x;
	float	new_y;
	float	old_x;
	float	old_y;

	old_x = main->player.pos_x;
	old_y = main->player.pos_y;
	new_x = main->player.pos_x - (0.1f * main->player.dir_y);
	new_y = main->player.pos_y + (0.1f * main->player.dir_x);
	if (check_collider_x(main, new_x, old_y))
		main->player.pos_x = new_x;
	if (check_collider_y(main, old_x, new_y))
		main->player.pos_y = new_y;
}

void    player_movement_left(t_main *main)
{
    float	new_x;
	float	new_y;
	float	old_x;
	float	old_y;

	old_x = main->player.pos_x;
	old_y = main->player.pos_y;
	new_x = main->player.pos_x + (0.1f * main->player.dir_y);
	new_y = main->player.pos_y - (0.1f * main->player.dir_x);
	if (check_collider_x(main, new_x, old_y))
		main->player.pos_x = new_x;
	if (check_collider_y(main, old_x, new_y))
		main->player.pos_y = new_y;
}