#include "cub3d.h"

void    key_action_press(mlx_key_data_t keydata, t_key *key)
{
    if(keydata.key == 87 && keydata.action == MLX_PRESS)
	    key->W = 1;
	if(keydata.key == 65 && keydata.action == MLX_PRESS)
		key->A = 1;
	if(keydata.key == 83 && keydata.action == MLX_PRESS)
		key->S = 1;
	if(keydata.key == 68 && keydata.action == MLX_PRESS)
		key->D = 1;
	if(keydata.key == 256 && key->esc == 1 && keydata.action == MLX_PRESS)
		key->esc = 0;
	else if(keydata.key == 256 && key->esc == 0 && keydata.action == MLX_PRESS)
		key->esc = 1;
}

void    key_action_release(mlx_key_data_t keydata, t_key *key)
{
	if(keydata.key == 87 && keydata.action == MLX_RELEASE)
		key->W = 0;
	if(keydata.key == 65 && keydata.action == MLX_RELEASE)
		key->A = 0;
	if(keydata.key == 83 && keydata.action == MLX_RELEASE)
		key->S = 0;
	if(keydata.key == 68 && keydata.action == MLX_RELEASE)
		key->D = 0;

}