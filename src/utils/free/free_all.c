/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:18:49 by arforgea          #+#    #+#             */
/*   Updated: 2023/09/08 16:52:34 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_wall_texture(t_texture **tab)
{
	int	i;

	i = 0;
	while (i <= 3)
	{
		if (tab[i] == NULL)
		{
			i++;
			continue ;
		}
		free(tab[i]->pixels);
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
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

void	free_all(t_main *main)
{
	free(main->ray_array);
	if (main->map.format_map)
		free_tab(main->map.format_map);
	free(main->map.texture_east);
	free(main->map.texture_west);
	free(main->map.texture_north);
	free(main->map.texture_south);
	if (main->wall_texture)
		free_wall_texture(main->wall_texture);
	mlx_terminate(main->mlx_data.mlx);
}
