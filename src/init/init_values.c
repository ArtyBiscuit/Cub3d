/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 14:53:27 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/07 10:21:41 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_values(t_main *main)
{
	main->ray_array = malloc(sizeof(t_ray) * WIDTH);

	//parameter
	main->parameter.fov = 90.0f;
	main->parameter.crossshair_size = 5;
	main->parameter.crossshair_color = 0xffff00ff;

	//fps
	main->frame_curent_time = 0;

	//player
	main->player.pos_x = 14.5f;
	main->player.pos_y = 3.5f;
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
	main->key.esc = 1;

	//map
	main->map.texture_north = NULL;
	main->map.texture_south = NULL;
	main->map.texture_east = NULL;
	main->map.texture_west = NULL;
	main->map.ceiling_color = 0;
	main->map.floor_color = 0;
	parsing_map_arg(&main->map, "maps/main_map.cub");
	main->map.size_x = get_map_size_x(main->map.format_map);
	main->map.size_y = get_map_size_y(main->map.format_map);

	//wall_textures
	main->wall_texture = malloc(sizeof(t_texture) * 4);
	main->wall_texture[0] = img_to_struct(mlx_texture_to_image(main->mlx_data.mlx, mlx_load_png(main->map.texture_north)));
	main->wall_texture[1] = img_to_struct(mlx_texture_to_image(main->mlx_data.mlx, mlx_load_png(main->map.texture_south)));
	main->wall_texture[2] = img_to_struct(mlx_texture_to_image(main->mlx_data.mlx, mlx_load_png(main->map.texture_east)));
	main->wall_texture[3] = img_to_struct(mlx_texture_to_image(main->mlx_data.mlx, mlx_load_png(main->map.texture_west)));

	//sprites
	main->sprite = malloc(sizeof(t_sprite));
	main->sprite[0].type = 1;
	main->sprite[0].state = 1;
	main->sprite[0].texture = img_to_struct(mlx_texture_to_image(main->mlx_data.mlx, mlx_load_png("./src/texture/mguard_shoot1.png")));
	main->sprite[0].x = 20.5f;
	main->sprite[0].y = 12.5f;
	main->sprite[0].z = -0.5f;

	return (0);
}
