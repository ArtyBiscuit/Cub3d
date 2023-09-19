/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 21:30:21 by arforgea          #+#    #+#             */
/*   Updated: 2023/09/19 17:57:55 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture(t_main main)
{
	int	error;
	int	index;
	int	*fd;

	fd = malloc(sizeof(int) * 4);
	error = 0;
	fd[0] = open(main.map.texture_east, O_RDONLY);
	fd[1] = open(main.map.texture_north, O_RDONLY);
	fd[2] = open(main.map.texture_south, O_RDONLY);
	fd[3] = open(main.map.texture_west, O_RDONLY);
	index = 0;
	while (index != 4)
	{
		if (fd[index] > -1)
			close(fd[index]);
		else
			error = -1;
		index++;
	}
	free(fd);
	if (error < 0)
		return (1);
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
	if (check_texture(*main))
		return (1);
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
	free_img(main, img_tmp, texture_tmp);
	return (0);
}
