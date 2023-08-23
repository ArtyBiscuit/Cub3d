/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:30:21 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 21:38:32 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_wall_texture(t_main *main)
{
	mlx_image_t		**img_tmp;
	mlx_texture_t	**texture_tmp;

	main->wall_texture = malloc(sizeof(t_texture) * 4);
	img_tmp = malloc(sizeof(mlx_image_t) * 4);
	texture_tmp = malloc(sizeof(mlx_texture_t) * 4);
	texture_tmp[0] = mlx_load_png(main->map.texture_north);
	texture_tmp[1] = mlx_load_png(main->map.texture_south);
	texture_tmp[2] = mlx_load_png(main->map.texture_east);
	texture_tmp[3] = mlx_load_png(main->map.texture_west);
	img_tmp[0] = mlx_texture_to_image(main->mlx_data.mlx, texture_tmp[0]);
	img_tmp[1] = mlx_texture_to_image(main->mlx_data.mlx, texture_tmp[1]);
	img_tmp[2] = mlx_texture_to_image(main->mlx_data.mlx, texture_tmp[2]);
	img_tmp[3] = mlx_texture_to_image(main->mlx_data.mlx, texture_tmp[3]);
	main->wall_texture[0] = img_to_struct(img_tmp[0]);
	main->wall_texture[1] = img_to_struct(img_tmp[1]);
	main->wall_texture[2] = img_to_struct(img_tmp[2]);
	main->wall_texture[3] = img_to_struct(img_tmp[3]);
}
