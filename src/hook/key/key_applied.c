/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_applied.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:31:51 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/24 18:37:38 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_applied(t_main *main)
{
	float	speed;

	speed = main->parameter.speed;
	if (main->key.w)
		player_movement_forward(main, speed);
	if (main->key.s)
		player_movement_back(main, speed);
	if (main->key.d)
		player_movement_right(main, speed);
	if (main->key.a)
		player_movement_left(main, speed);
	if (main->key.left)
		player_rotate(main, -0.1 * main->parameter.sensitivity);
	if (main->key.right)
		player_rotate(main, 0.1 * main->parameter.sensitivity);
	if (main->key.esc)
		exit(0);
}
