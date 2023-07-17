/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:30 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/17 14:27:46 by axcallet         ###   ########.fr       */
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
	i += count;
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
	char	*line;
	char	*line_tmp;
	char	**map;

	line_tmp = NULL;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line_tmp = ft_strjoin(line_tmp, line);
		free(line);
		line = get_next_line(fd);
	}
	map = ft_split(line_tmp, '\n');
	close(fd);
	return (map);
}

void	parsing_map_arg(t_map *map, char *file)
{
	char	**tab_file;

	tab_file = file_to_tab_char(file);
	parsing_arguments(&map, tab_file);
	parsing_map(&map, tab_file);
}