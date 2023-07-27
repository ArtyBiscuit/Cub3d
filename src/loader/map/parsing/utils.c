/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:16:26 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/27 15:53:03 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_upper_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	check_arg_are_refile(t_map map)
{
	if (!map.texture_north || !map.texture_south || !map.texture_west
		|| !map.texture_east || !map.floor_color || !map.ceiling_color)
		return (1);
	return (0);
}

int	map_len(char **tab_file, int i)
{
	int	size;

	size = 0;
	while (tab_file[i])
	{
		if (!ft_strncmp(tab_file[i], "NO", 2)
			|| !ft_strncmp(tab_file[i], "SO", 2)
			|| !ft_strncmp(tab_file[i], "WE", 2)
			|| !ft_strncmp(tab_file[i], "EA", 2)
			|| !ft_strncmp(tab_file[i], "F", 1)
			|| !ft_strncmp(tab_file[i], "C", 1))
		{
			ft_putstr_fd("Error: bad line\n", 2);
			exit(1);
		}
		i++;
		size++;
	}
	return (size);
}
