/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:18:49 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/24 10:33:19 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_wall_texture(t_texture **tab)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		free(tab[i]->pixels);
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_all(t_main *main)
{
	free_ray_array(main->ray_array);
	free_tab(main->map.format_map);
	free(main->map.texture_east);
	free(main->map.texture_west);
	free(main->map.texture_north);
	free(main->map.texture_south);
	free_wall_texture(main->wall_texture);
	mlx_terminate(main->mlx_data.mlx);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}
