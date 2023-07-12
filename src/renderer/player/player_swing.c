/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_swing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:31:24 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/29 18:31:44 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/cub3d.h"

void	player_rotate(t_main *main, float theta)
{
	float	new_x;
	float	new_y;
	float	new_plane_x;
	float	new_plane_y;

	new_x = cos(theta) * main->player.dir_x - sin(theta) * main->player.dir_y;
	new_y = sin(theta) * main->player.dir_x + cos(theta) * main->player.dir_y;
	new_plane_x = cos(theta) * main->player.plane_x - sin(theta) * main->player.plane_y;
	new_plane_y = sin(theta) * main->player.plane_x + cos(theta) * main->player.plane_y;
	main->player.dir_x = new_x;
	main->player.dir_y = new_y;
	main->player.plane_x = new_plane_x;
	main->player.plane_y = new_plane_y;
}
