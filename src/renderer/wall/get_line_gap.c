/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_gap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:22:59 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 19:40:31 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_line_gap(t_texture *texture, t_ray *ray, t_main *main)
{
	double	wall_x;
	double	wall_text_x;

	wall_x = 0.0;
	if (ray->side == 0)
		wall_x = main->player.pos_y + get_ray_min_dist(*ray) * ray->ray_dir_y;
	else if (ray->side == 1)
		wall_x = main->player.pos_x + get_ray_min_dist(*ray) * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	wall_text_x = (int)(wall_x * texture->size_x);
	return (wall_text_x);
}
