#include "../inc/cub3d.h"
#include <math.h>
#include <stdbool.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>


// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	t_main		main;

	char	*test = malloc(sizeof(char) * 0x10);

	memset(test, 0,  0x10);

	free(test);
	test = NULL;

	main.mlx_data.mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!main.mlx_data.mlx)
		ft_error();

	main.mlx_data.img = mlx_new_image(main.mlx_data.mlx, WIDTH, HEIGHT);
	if (!main.mlx_data.img || (mlx_image_to_window(main.mlx_data.mlx, main.mlx_data.img, 0, 0) < 0))
		ft_error();

	init_values(&main);
	test = malloc(0x10);

	strcpy(test, "hello world\0");

	printf("%s\n", test);

	free(test);
	test = NULL;

	load_sprite(&main);

	mlx_key_hook(main.mlx_data.mlx, key_hook, &main.key);
	mlx_loop_hook(main.mlx_data.mlx, loop_hook, &main);
	mlx_loop(main.mlx_data.mlx);
	free_all(&main);
	return (EXIT_SUCCESS);
}
