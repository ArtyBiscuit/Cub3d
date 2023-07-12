/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:14:05 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/29 17:14:29 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/cub3d.h"

void	get_wall_color(int **map, t_ray *ray)
{
	int wall_color;

	if (map[ray->ray_pos_x][ray->ray_pos_y] == 1)
		wall_color = 0xf54242ff;
	else if (map[ray->ray_pos_x][ray->ray_pos_y] == 2)
		wall_color = 0x325efcff;
	else if (map[ray->ray_pos_x][ray->ray_pos_y] == 3)
		wall_color = 0x32fc62ff;
	else if (map[ray->ray_pos_x][ray->ray_pos_y] == 4)
		wall_color = 0xe6d11cff;
	else
		wall_color = 0xffffffff;
	if (ray->side == 1)
		wall_color /= 1.5;
	ray->wall_color = wall_color;
}
