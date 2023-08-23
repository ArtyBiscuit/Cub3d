/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rey_side.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 18:00:48 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 18:47:11 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_ray_side(t_player player, t_ray *curent_ray)
{
	float	d_x;
	float	d_y;

	d_x = curent_ray->delta_x;
	d_y = curent_ray->delta_y;
	if (curent_ray->ray_dir_x < 0)
	{
		curent_ray->step_x = -1;
		curent_ray->dist_x = (player.pos_x - curent_ray->ray_pos_x) * d_x;
	}
	else
	{
		curent_ray->step_x = 1;
		curent_ray->dist_x = (curent_ray->ray_pos_x + 1 - player.pos_x) * d_x;
	}
	if (curent_ray->ray_dir_y < 0)
	{
		curent_ray->step_y = -1;
		curent_ray->dist_y = (player.pos_y - curent_ray->ray_pos_y) * d_y;
	}
	else
	{
		curent_ray->step_y = 1;
		curent_ray->dist_y = (curent_ray->ray_pos_y + 1 - player.pos_y) * d_y;
	}
}
