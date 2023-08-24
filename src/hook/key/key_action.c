/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:35:17 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/24 18:37:08 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_action_press(mlx_key_data_t keydata, t_key *key)
{
	if (keydata.key == 87 && keydata.action == MLX_PRESS)
		key->w = 1;
	if (keydata.key == 65 && keydata.action == MLX_PRESS)
		key->a = 1;
	if (keydata.key == 83 && keydata.action == MLX_PRESS)
		key->s = 1;
	if (keydata.key == 68 && keydata.action == MLX_PRESS)
		key->d = 1;
	if (keydata.key == 263 && keydata.action == MLX_PRESS)
		key->left = 1;
	if (keydata.key == 262 && keydata.action == MLX_PRESS)
		key->right = 1;
}

void	key_action_release(mlx_key_data_t keydata, t_key *key)
{
	if (keydata.key == 87 && keydata.action == MLX_RELEASE)
		key->w = 0;
	if (keydata.key == 65 && keydata.action == MLX_RELEASE)
		key->a = 0;
	if (keydata.key == 83 && keydata.action == MLX_RELEASE)
		key->s = 0;
	if (keydata.key == 68 && keydata.action == MLX_RELEASE)
		key->d = 0;
	if (keydata.key == 263 && keydata.action == MLX_RELEASE)
		key->left = 0;
	if (keydata.key == 262 && keydata.action == MLX_RELEASE)
		key->right = 0;
}
