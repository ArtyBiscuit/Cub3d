/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:53:00 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/20 19:29:43 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_main *main, t_ray *ray_array)
{
	draw_ceiling(main, main->map.ceiling_color);
	draw_floor(main, main->map.floor_color);
	draw_wall(main, ray_array);
	crosshair(main);
}
