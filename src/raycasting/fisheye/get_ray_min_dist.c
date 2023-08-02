/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_min_dist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:20:33 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/01 16:50:51 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	get_ray_min_dist(t_ray ray)
{
	float min_dist;

	if (ray.dist_x < ray.dist_y)
		min_dist = ray.dist_x;
	else
		min_dist = ray.dist_y;
	min_dist /= sqrt(ray.ray_dir_x * ray.ray_dir_x + ray.ray_dir_y * ray.ray_dir_y);
	return (min_dist);
}
