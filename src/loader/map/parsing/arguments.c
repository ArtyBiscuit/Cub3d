/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:15:58 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/18 14:11:42 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*get_wall_texture(char *line)
{
	int		i;
	int		j;
	char	*wall_texture;

	i = 2;
	while (is_space(line[i]))
		i++;
	j = i;
	while (line[i] && !is_space(line[i]))
		i++;
	wall_texture = ft_substr(line, j, (i - j));
	return (wall_texture);
}

static int	*get_floor_ceiling_texture(char *line)
{
	int		i;
	int		j;
	int		count;
	int		*tab_rgb;

	i = 1;
	count = 0;
	tab_rgb = malloc(sizeof(int) * 3);
	while (is_space(line[i]))
		i++;
	while (count != 3)
	{
		j = i;
		while (line[i] != ',')
			i++;
		tab_rgb[count] = ft_atoi(ft_substr(line, j, ((i - j) - 1)));
		count++;
	}
	return (tab_rgb);
}

static void	refile_textures(t_map *map, char *line)
{
	int	i;

	i = 0;
	while (is_space(line[i]))
		i++;
	if (!ft_strncmp(line, "NO ", 3) && !map->texture_north)
		map->texture_north = get_wall_texture(&line[i]);
	else if (!ft_strncmp(line, "SO ", 3) && !map->texture_south)
		map->texture_south = get_wall_texture(&line[i]);
	else if (!ft_strncmp(line, "WE ", 3) && !map->texture_west)
		map->texture_west = get_wall_texture(&line[i]);
	else if (!ft_strncmp(line, "EA ", 3) && !map->texture_east)
		map->texture_east = get_wall_texture(&line[i]);
	else if (!ft_strncmp(line, "F ", 2) && !map->floor_color)
		map->floor_color = get_floor_ceiling_texture(&line[i]);
	else if (!ft_strncmp(line, "C ", 2) && !map->ceiling_color)
		map->ceiling_color = get_floor_ceiling_texture(&line[i]);
	else
	{
		ft_putstr_fd("Error, incorrect texture\n", 2);
		exit(1);
	}
}

int	parsing_arguments(t_map *map, char **tab_file)
{
	int	i;

	i = 0;
	while (check_arg_are_refile(*map))
	{
		if (tab_file[i][0] == '\n')
			i++;
		else if (check_arg_format(tab_file[i]))
		{
			ft_putstr_fd("Error, incorrect format texture\n", 2);
			printf("ligne %d\n", (i + 1));
			exit(1);
		}
		else
		{
			refile_textures(map, tab_file[i]);
			i++;
		}
	}
	return (i);
}
