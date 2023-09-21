/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:15:58 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/21 09:22:37 by axcallet         ###   ########.fr       */
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

static int	refile_color(char *str)
{
	int		i;
	int		j;
	int		res;
	char	*buff;

	i = 0;
	j = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	buff = ft_substr(str, j, i);
	res = ft_atoi(buff);
	free(buff);
	return (res);
}

static int	get_color(char *str)
{
	int	i;
	int	j;
	int	buff;
	int	*tab;

	i = 1;
	j = 0;
	tab = malloc(sizeof(int) * 3);
	tab[0] = -1;
	tab[1] = -1;
	tab[2] = -1;
	while (check_color_refile(tab))
	{
		while (str[i] && str[i] == ' ')
			i++;
		tab[j++] = refile_color(&str[i]);
		while (str[i] && str[i] != ',')
			i++;
		if (str[i])
			i++;
	}
	buff = rgba_to_hex(tab[0], tab[1], tab[2], 255);
	free(tab);
	return (buff);
}

static int	refile_textures(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (!ft_strncmp(&line[i], "NO ", 3) && !map->texture_north)
		map->texture_north = get_texture(&line[i]);
	else if (!ft_strncmp(&line[i], "SO ", 3) && !map->texture_south)
		map->texture_south = get_texture(&line[i]);
	else if (!ft_strncmp(&line[i], "WE ", 3) && !map->texture_west)
		map->texture_west = get_texture(&line[i]);
	else if (!ft_strncmp(&line[i], "EA ", 3) && !map->texture_east)
		map->texture_east = get_texture(&line[i]);
	else if (!ft_strncmp(&line[i], "F ", 2) && !map->floor_color)
		map->floor_color = get_color(&line[i]);
	else if (!ft_strncmp(&line[i], "C ", 2) && !map->ceiling_color)
		map->ceiling_color = get_color(&line[i]);
	else
		return (1);
	return (0);
}

int	parsing_arguments(t_map *map, char **tab_file)
{
	int	i;

	i = 0;
	while (check_arg_are_refile(*map))
	{
		if (!check_empty_line(tab_file[i]))
			i++;
		else if (check_arg_format(tab_file[i]))
			return (1);
		else if (refile_textures(map, tab_file[i]))
			return (1);
		else
			i++;
	}
	if (check_empty_line(tab_file[i]))
		return (1);
	return (i);
}
