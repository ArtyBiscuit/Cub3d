/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:15:58 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/30 14:44:34 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_texture(char *line)
{
	int		i;
	int		j;
	char	*wall_texture;

	i = 2;
	while (is_space(line[i]))
		i++;
	j = i;
	while (line[i] && !is_space(line[i]) && line[i] != '\n')
		i++;
	wall_texture = ft_substr(line, j, (i - j));
	return (wall_texture);
}

static int	*refile_tab_color(char *line)
{
	int		i;
	int		j;
	int		count;
	int		*tab_rgb;
	char	*tmp;

	i = 1;
	count = 0;
	tab_rgb = malloc(sizeof(int) * 3);
	while (is_space(line[i]))
		i++;
	while (count != 3)
	{
		j = i;
		while (line[i] && line[i] != ',')
			i++;
		tmp = ft_substr(line, j, (i - j));
		tab_rgb[count] = ft_atoi(tmp);
		free(tmp);
		i++;
		count++;
	}
	return (tab_rgb);
}

static int	get_floor_ceiling_color(char *line)
{
	int	hex;
	int	*tab_rgb;

	tab_rgb = refile_tab_color(line);
	hex = rgba_to_hex(tab_rgb[0], tab_rgb[1], tab_rgb[2], 255);
	free(tab_rgb);
	return (hex);
}

static int	refile_textures(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (!ft_strncmp(line, "NO ", 3) && !map->texture_north)
		map->texture_north = get_texture(&line[i]);
	else if (!ft_strncmp(line, "SO ", 3) && !map->texture_south)
		map->texture_south = get_texture(&line[i]);
	else if (!ft_strncmp(line, "WE ", 3) && !map->texture_west)
		map->texture_west = get_texture(&line[i]);
	else if (!ft_strncmp(line, "EA ", 3) && !map->texture_east)
		map->texture_east = get_texture(&line[i]);
	else if (!ft_strncmp(line, "F ", 2) && !map->floor_color)
		map->floor_color = get_floor_ceiling_color(&line[i]);
	else if (!ft_strncmp(line, "C ", 2) && !map->ceiling_color)
		map->ceiling_color = get_floor_ceiling_color(&line[i]);
	else
	{
		ft_putstr_fd("ERROR:\tthe texture already exists\n", 2);
		return (1);
	}
	return (0);
}

int	parsing_arguments(t_map *map, char **tab_file)
{
	int	i;

	i = 0;
	while (check_arg_are_refile(*map))
	{
		if (tab_file[i] && tab_file[i][0] == '\n')
			i++;
		else if (check_arg_format(tab_file[i]))
			return (1);
		else if (refile_textures(map, tab_file[i]))
			return (1);
		else
			i++;
	}
	return (i);
}
