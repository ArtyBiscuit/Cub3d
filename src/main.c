/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:24:39 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/23 10:36:32 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	t_main		main;

	main.mlx_data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!main.mlx_data.mlx)
		ft_error();
	main.mlx_data.img = mlx_new_image(main.mlx_data.mlx, WIDTH, HEIGHT);
	if (!main.mlx_data.img)
		ft_error();
	if (mlx_image_to_window(main.mlx_data.mlx, main.mlx_data.img, 0, 0) < 0)
		ft_error();
	init_values(&main);
	mlx_key_hook(main.mlx_data.mlx, key_hook, &main.key);
	mlx_loop_hook(main.mlx_data.mlx, loop_hook, &main);
	mlx_loop(main.mlx_data.mlx);
	free_all(&main);
	return (EXIT_SUCCESS);
}
