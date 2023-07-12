/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:22:23 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/30 17:28:45 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/cub3d.h"

static int	raycast(t_main *main, t_ray *ray_array)
{
	t_ray	*ray;
	int		cmp;

	cmp = 0;
	while (cmp < WIDTH)
	{
		ray = &ray_array[cmp];
		ray->ray_id = cmp;
		ray->plane_ratio = 2.0f * cmp / ((float)WIDTH) - 1;
		ray->ray_dir_x = main->player.dir_x + main->player.plane_x * ray->plane_ratio;
		ray->ray_dir_y = main->player.dir_y + main->player.plane_y * ray->plane_ratio;
		check_infinite_value(ray);
		ray->ray_pos_x = (int)main->player.pos_x;
		ray->ray_pos_y = (int)main->player.pos_y;
		get_ray_side(main->player, ray);
		perform_dda(main->map_data.format_map, ray);
		cmp++;
	}
	return (0);
}

void	algo(t_main *main, t_ray *ray_array)
{
    raycast(main, ray_array);
}
