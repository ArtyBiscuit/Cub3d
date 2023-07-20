/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:53:27 by arforgea          #+#    #+#             */
/*   Updated: 2023/07/20 15:43:19 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_values(t_main *main)
{
	main->ray_array = malloc(sizeof(t_ray) * WIDTH);

	ft_memset(main->ray_array, 0, sizeof(t_ray) * WIDTH);

	//parameter
	main->parameter.fov = 90.0f;
	main->parameter.crossshair_size = 5;
	main->parameter.crossshair_color = 0xffff00ff;

	//fps
	main->frame_curent_time = 0;

	//player
	main->player.pos_x = 1.5f;
	main->player.pos_y = 1.5f;
	main->player.dir_x = 1;
	main->player.dir_y = 0;
	main->player.plane_x = 0;
	main->player.plane_y = tan(deg_converter(main->parameter.fov / 2));
	main->player.theta = 0;
	main->player.view = 0;

	//key
	main->key.W = 0;
	main->key.A = 0;
	main->key.S = 0;
	main->key.D = 0;
	main->key.esc = 0;

	//map
	main->map.texture_north = NULL;
	main->map.texture_south = NULL;
	main->map.texture_west = NULL;
	main->map.texture_east = NULL;
	main->map.floor_color = 0;
	main->map.ceiling_color = 0;
	parsing_map_arg(&main->map, "maps/main_map.cub");

	return (0);
}
