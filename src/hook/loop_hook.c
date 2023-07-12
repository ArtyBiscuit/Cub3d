/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:31:46 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/30 17:21:55 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/cub3d.h"
// Print the window width and height.
void	game_fps(t_main *main)
{
	main->frame_old_time = main->frame_curent_time;
	main->frame_curent_time = mlx_get_time();
	printf("\e[1A\e[2KFPS: %2.f\n", 1.0 / (main->frame_curent_time - main->frame_old_time));
}

void loop_hook(void* param)
{
	t_main	*main;

	main = param;
	game_fps(main);
	ft_memset(main->mlx_data.img->pixels, 0, main->mlx_data.img->width * main->mlx_data.img->height * sizeof(int32_t));
	key_applied(main);
	algo(main, main->ray_array);
	render(main, main->ray_array);
	
	return ;
}
