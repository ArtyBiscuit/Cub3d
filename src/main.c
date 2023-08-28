/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 18:24:39 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/28 17:52:40 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

static void	check_input(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Wrong number of arguments\n", 2);
		exit(1);
	}
	if (ft_strncmp(argv[1], ".cub", ft_strlen(argv[1]) - 4))
	{
		ft_putstr_fd("Wrong file extension\n", 2);
		exit(1);
	}
	if (open(argv[1], O_RDONLY) < 0)
	{
		ft_putstr_fd("Cannot open the file\n", 2);
		exit(1);
	}
}

int32_t	main(int argc, char **argv)
{
	t_main		main;

	check_input(argc, argv);
	init_values(&main, argv[1]);
	main.mlx_data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!main.mlx_data.mlx)
		ft_error();
	main.mlx_data.img = mlx_new_image(main.mlx_data.mlx, WIDTH, HEIGHT);
	if (!main.mlx_data.img)
		ft_error();
	if (mlx_image_to_window(main.mlx_data.mlx, main.mlx_data.img, 0, 0) < 0)
		ft_error();
	mlx_key_hook(main.mlx_data.mlx, key_hook, &main.key);
	mlx_loop_hook(main.mlx_data.mlx, loop_hook, &main);
	mlx_loop(main.mlx_data.mlx);
	free_all(&main);
	return (EXIT_SUCCESS);
}
