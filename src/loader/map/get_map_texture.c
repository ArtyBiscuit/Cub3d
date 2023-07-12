/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:28:55 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/14 16:34:32 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../../inc/cub3d.h"

int	get_map_texture(t_map *map_struct, int map_fd)
{
	char	*current_texture;
	int		i;

	i = 0;
	while (i < 4)
	{
		current_texture = get_next_line(map_fd);

	}
}
