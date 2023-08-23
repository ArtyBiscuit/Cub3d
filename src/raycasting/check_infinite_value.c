/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_infinite_value.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:25:54 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 18:57:01 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_infinite_value(t_ray *ray)
{
	float	a;
	float	b;

	a = (ray->ray_dir_y * ray->ray_dir_y);
	b = (ray->ray_dir_x * ray->ray_dir_x);
	if (ray->ray_dir_x == 0)
		ray->delta_x = 1e30;
	else
		ray->delta_x = sqrt(1 + a / b);
	if (ray->ray_dir_y == 0)
		ray->delta_y = 1e30;
	else
		ray->delta_y = sqrt(1 + b / a);
}
