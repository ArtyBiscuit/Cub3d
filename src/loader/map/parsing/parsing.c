/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:12:30 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/24 16:26:26 by axcallet         ###   ########.fr       */
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
	tab_file = malloc(sizeof(char *) * (index + 1));
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
	tab_file[index] = NULL;
	return (tab_file);
}

int	map_len(char **tab_file, int i)
{
	int	size;

	size = 0;
	while(tab_file[i])
	{
		if (!ft_strncmp(tab_file[i], "NO", 2) || !ft_strncmp(tab_file[i], "SO", 2)
			|| !ft_strncmp(tab_file[i], "WE", 2) || !ft_strncmp(tab_file[i], "EA", 2)
			|| !ft_strncmp(tab_file[i], "F", 1) || !ft_strncmp(tab_file[i], "C", 1))
		{
			printf("%s\n", tab_file[i]);
			ft_putstr_fd("Error: bad line\n", 2);
			exit(1);
		}
		i++;
		size++;
	}
	return (size);
}

void	parsing_map_arg(t_map *map, char *file)
{
	int		size;
	int		index;
	char	**tab_file;

	size = 0;
	index = 0;
	tab_file = file_to_tab_char(file);
	index = parsing_arguments(map, tab_file);
	printf("%d\n", index);
	size = map_len(tab_file, index);
	map->format_map = malloc(sizeof(char*) * size + 1);
	parsing_map(map, tab_file, (index + 1));
}
