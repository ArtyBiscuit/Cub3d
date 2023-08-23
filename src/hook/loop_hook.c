/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:31:46 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/23 10:37:06 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_hook(void *param)
{
	t_main		*main;
	mlx_image_t	*img;

	main = param;
	img = main->mlx_data.img;
	ft_memset(img->pixels, 0, img->width * img->height * sizeof(int32_t));
	key_applied(main);
	algo(main, main->ray_array);
	render(main, main->ray_array);
	return ;
}
