/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:53:27 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/23 10:38:21 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_parameter(t_main *main)
{
	printf("INIT:\tParameter...\n");
	main->parameter.speed = 0.1;
	main->parameter.fov = 90.0f;
	main->parameter.crossshair_size = 5;
	main->parameter.crossshair_color = 0xffff00ff;
	main->parameter.sensitivity = 1.0f;
}

void	init_player_valus(t_main *main)
{
	main->player.dir_x = 1;
	main->player.dir_y = 0;
	main->player.pos_x = 0.0;
	main->player.pos_y = 0.0;
	main->player.plane_x = 0;
	main->player.plane_y = tan(deg_converter(main->parameter.fov / 2));
	main->player.theta = 0;
	main->player.view = 0;
}

void	set_default_key_valus(t_main *main)
{
	main->key.W = 0;
	main->key.A = 0;
	main->key.S = 0;
	main->key.D = 0;
	main->key.left = 0;
	main->key.right = 0;
}

void	init_map_valus(t_main *main)
{
	main->map.texture_north = NULL;
	main->map.texture_south = NULL;
	main->map.texture_east = NULL;
	main->map.texture_west = NULL;
	main->map.floor_color = 0;
	main->map.ceiling_color = 0;
	parsing_map_arg(main, "maps/main_map.cub");
	main->map.size_x = get_map_size_x(main->map.format_map);
	main->map.size_y = get_map_size_y(main->map.format_map);
}

int	init_values(t_main *main)
{
	main->frame_curent_time = 0;
	main->ray_array = malloc(sizeof(t_ray) * WIDTH);
	if (!main->ray_array)
		return (1);
	init_parameter(main);
	init_player_valus(main);
	set_default_key_valus(main);
	init_map_valus(main);
	load_wall_texture(main);
	return (0);
}
