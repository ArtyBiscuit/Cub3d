/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:22:23 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/24 17:43:32 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	algo(t_main *main, t_ray *ray_array)
{
	t_ray	*ray;
	int		cmp;

	cmp = 0;
	while (cmp < WIDTH)
	{
		ray = &ray_array[cmp];
		ray->ray_id = cmp;
		ray->pl = 2.0f * cmp / ((float)WIDTH) - 1;
		ray->ray_dir_x = main->player.dir_x + main->player.plane_x * ray->pl;
		ray->ray_dir_y = main->player.dir_y + main->player.plane_y * ray->pl;
		check_infinite_value(ray);
		ray->ray_pos_x = (int)main->player.pos_x;
		ray->ray_pos_y = (int)main->player.pos_y;
		get_ray_side(main->player, ray);
		perform_dda(main->map.format_map, ray);
		ray->wall_side = get_cardinal_side(ray);
		cmp++;
	}
}
