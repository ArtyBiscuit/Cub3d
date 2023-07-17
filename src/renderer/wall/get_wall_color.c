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

void	get_wall_color(char **map, t_ray *ray)
{
	int wall_color;

	if (map[ray->ray_pos_x][ray->ray_pos_y] == '1')
		wall_color = 0xf54242ff;
	else
		wall_color = 0xffffffff;
	if (ray->side == 1)
		wall_color /= 1.5;
	ray->wall_color = wall_color;
}
