/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_swing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:31:24 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 19:07:38 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"

void	player_rotate(t_main *main, float theta)
{
	float	new_x;
	float	new_y;
	float	x;
	float	y;

	new_x = cos(theta) * main->player.dir_x - sin(theta) * main->player.dir_y;
	new_y = sin(theta) * main->player.dir_x + cos(theta) * main->player.dir_y;
	x = cos(theta) * main->player.plane_x - sin(theta) * main->player.plane_y;
	y = sin(theta) * main->player.plane_x + cos(theta) * main->player.plane_y;
	main->player.dir_x = new_x;
	main->player.dir_y = new_y;
	main->player.plane_x = x;
	main->player.plane_y = y;
}
