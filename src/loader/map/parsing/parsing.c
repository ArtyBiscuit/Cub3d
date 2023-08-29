/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:30 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/29 13:57:21 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**refile_tab(char *file, int i)
{
	int		fd;
	int		index;
	char	*line;
	char	**tab_file;

	index = 0;
	fd = open(file, O_RDONLY);
	tab_file = malloc(sizeof(char *) * (i + 1));
	line = get_next_line(fd);
	while (line)
	{
		tab_file[index] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		index++;
	}
	tab_file[index] = NULL;
	free(line);
	close(fd);
	return (tab_file);
}

static char	**file_to_tab_char(char *file)
{
	int		i;
	int		fd;
	char	*line;
	char	**tab_file;

	i = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		ft_putstr_fd("Error: empty file\n", 2);
		exit(1);
	}
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	tab_file = refile_tab(file, i);
	return (tab_file);
}

int	parsing_map_arg(t_main *main, char *file)
{
	int		size;
	int		index;
	char	**tab_file;

	tab_file = file_to_tab_char(file);
	index = parsing_arguments(&main->map, tab_file);
	if (index == 1)
	{
		free_tab(tab_file);
		return (1);
	}
	size = map_len(tab_file, index);
	if (size == 1)
	{
		free_tab(tab_file);
		return (1);
	}
	main->map.format_map = malloc(sizeof(char *) * size+ 1);
	if (parsing_map(main, tab_file, (index + 1)))
	{
		free_tab(tab_file);
		free_tab(main->map.format_map);
		return (1);
	}
	return (0);
}
