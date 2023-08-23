/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_applied.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:31:51 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 18:33:56 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_applied(t_main *main)
{
	float	speed;

	speed = main->parameter.speed;
	if (main->key.W)
		player_movement_forward(main, speed);
	if (main->key.S)
		player_movement_back(main, speed);
	if (main->key.D)
		player_movement_right(main, speed);
	if (main->key.A)
		player_movement_left(main, speed);
	if (main->key.left)
		player_rotate(main, -0.1 * main->parameter.sensitivity);
	if (main->key.right)
		player_rotate(main, 0.1 * main->parameter.sensitivity);
}
