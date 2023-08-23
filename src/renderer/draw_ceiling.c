/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceiling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:03:27 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 19:35:01 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_ceiling(t_main *main, int color)
{
	int	i;
	int	j;
	int	k;
	int	new_color;

	i = (HEIGHT / 2) + main->player.view;
	k = 0;
	while (i > 0)
	{
		new_color = set_back_fog(color, k, 0xFF);
		j = 0;
		while (j < WIDTH)
		{
			if (i < HEIGHT && i >= 0)
				mlx_put_pixel(main->mlx_data.img, j, i, new_color);
			j++;
		}
		if (k > -400)
			k--;
		i--;
	}
}
