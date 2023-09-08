/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:30:21 by arforgea          #+#    #+#             */
/*   Updated: 2023/09/07 19:44:34 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture(mlx_texture_t **texture_tmp)
{
	int	index;
	int	free;

	index = 0;
	free = 0;
	while (index < 4)
	{
		if (texture_tmp[index] == NULL)
		{
			while (free < 4)
			{
				if (texture_tmp[index])
					mlx_delete_texture(texture_tmp[free]);
				free++;
			}
			return (1);
		}
		index++;
	}
	return (0);
}

static void	free_img(t_main *main, mlx_image_t **img, mlx_texture_t **texture)
{
	mlx_delete_image(main->mlx_data.mlx, img[0]);
	mlx_delete_image(main->mlx_data.mlx, img[1]);
	mlx_delete_image(main->mlx_data.mlx, img[2]);
	mlx_delete_image(main->mlx_data.mlx, img[3]);
	mlx_delete_texture(texture[0]);
	mlx_delete_texture(texture[1]);
	mlx_delete_texture(texture[2]);
	mlx_delete_texture(texture[3]);
	free(img);
	free(texture);
}

int	load_wall_texture(t_main *main)
{
	mlx_image_t		**img_tmp;
	mlx_texture_t	**texture_tmp;

	printf("STATUS:\tLoad Texture...\n");
	main->wall_texture = malloc(sizeof(t_texture) * 4);
	img_tmp = malloc(sizeof(mlx_image_t) * 4);
	texture_tmp = malloc(sizeof(mlx_texture_t) * 4);
	texture_tmp[0] = mlx_load_png(main->map.texture_north);
	texture_tmp[1] = mlx_load_png(main->map.texture_south);
	texture_tmp[2] = mlx_load_png(main->map.texture_east);
	texture_tmp[3] = mlx_load_png(main->map.texture_west);
	if(check_texture(texture_tmp))
		return (1);
	img_tmp[0] = mlx_texture_to_image(main->mlx_data.mlx, texture_tmp[0]);
	img_tmp[1] = mlx_texture_to_image(main->mlx_data.mlx, texture_tmp[1]);
	img_tmp[2] = mlx_texture_to_image(main->mlx_data.mlx, texture_tmp[2]);
	img_tmp[3] = mlx_texture_to_image(main->mlx_data.mlx, texture_tmp[3]);
	main->wall_texture[0] = img_to_struct(img_tmp[0]);
	main->wall_texture[1] = img_to_struct(img_tmp[1]);
	main->wall_texture[2] = img_to_struct(img_tmp[2]);
	main->wall_texture[3] = img_to_struct(img_tmp[3]);
	free_img(main, img_tmp, texture_tmp);
	return (0);
}
