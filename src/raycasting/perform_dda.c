/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:27:04 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/29 18:00:31 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/cub3d.h"

static void	increment_step(t_ray *ray)
{
	if (ray->dist_x < ray->dist_y)
	{
		ray->ray_pos_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->ray_pos_y += ray->step_y;
		ray->side = 1;
	}
}

static void	increment_delta(t_ray *ray)
{
	if (ray->dist_x < ray->dist_y)
	{
		ray->dist_x += ray->delta_x;
		ray->side = 0;
	}
	else
	{
		ray->dist_y += ray->delta_y;
		ray->side = 1;
	}
}

void	perform_dda(char **map, t_ray *ray)
{
	int	hit;

	hit = 0;
	while(hit == 0)
	{
		increment_step(ray);
		if (map[ray->ray_pos_x][ray->ray_pos_y] == '1')
		{
			hit = 1;
			return ;
		}
		increment_delta(ray);
	}
}
