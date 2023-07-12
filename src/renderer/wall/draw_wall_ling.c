/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_ling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:13:25 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/29 17:13:39 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/cub3d.h"

void	draw_line(t_main *main, int start, int end, t_ray ray)
{
	if (end < 0 ||end > HEIGHT)
		end = HEIGHT;
	while (start++ != end)
	{
		if (start < 0 && start > HEIGHT)
			continue;
		mlx_put_pixel(main->mlx_data.img, ray.ray_id, start, ray.wall_color);
	}
}
