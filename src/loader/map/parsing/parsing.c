/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:30 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/18 14:12:09 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg_format(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!is_upper_case(arg[i]))
		return (1);
	while (ft_isalpha(arg[i]))
	{
		if (!is_upper_case(arg[i]))
			return (1);
		i++;
		count++;
	}
	if (count != 2 && count != 1)
		return (1);
	if (!is_space(arg[i]))
		return (1);
	while (is_space(arg[i++]))
	{
		if (arg[i + 1] == '\0')
			return (1);
	}
	return (0);
}

static char	**file_to_tab_char(char *file)
{
	int		fd;
	int		index;
	char	*line;
	char	**tab_file;

	index = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		index++;
		line = get_next_line(fd);
	}
	tab_file = malloc(sizeof(char *) * index);
	close(fd);
	index = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tab_file[index] = ft_strdup(line);
		line = get_next_line(fd);
		index++;
	}
	return (tab_file);
}

int	map_len(char **tab_file)
{
	int i;

	i = 0;
	while(tab_file[i])
		i++;
	return (i - 8);
}

void	parsing_map_arg(t_map *map, char *file)
{
	int		index;
	char	**tab_file;

	tab_file = file_to_tab_char(file);
	index = parsing_arguments(map, tab_file);
	map->format_map = malloc(sizeof(char) * map_len(tab_file) + 1);
	parsing_map(map, tab_file, index);
}
