/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:19:15 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/27 16:44:36 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*refile_new_line(char **template, int max_len, int i)
{
	int		j;
	char	*new_line;

	j = 0;
	new_line = malloc(sizeof(char) * (max_len + 1));
	while (template[i][j])
	{
		new_line[j] = template[i][j];
		j++;
	}
	while (j != max_len)
		new_line[j++] = ' ';
	new_line[j] = '\0';
	return (new_line);
}

static char	**reformatting_map(char **template)
{
	int		i;
	int		max_len;
	char	**new_map;

	i = 0;
	max_len = 0;
	new_map = NULL;
	while (template[i])
	{
		if ((int)ft_strlen(template[i]) > max_len)
			max_len = ft_strlen(template[i]);
		i++;
	}
	new_map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (template[i])
	{
		new_map[i] = refile_new_line(template, max_len, i);
		i++;
	}
	new_map[i] = NULL;
	free_tab(template);
	return (new_map);
}

static int	check_plot_zero(char **file, int i, int j)
{
	if (file[i - 1][j] && file[i - 1][j] != '1' && file[i - 1][j] != '0'
		&& file[i - 1][j] != 'N' && file[i - 1][j] != 'S'
		&& file[i - 1][j] != 'W' && file[i - 1][j] != 'E')
		return (1);
	if (file[i + 1][j] && file[i + 1][j] != '1' && file[i + 1][j] != '0'
		&& file[i + 1][j] != 'N' && file[i + 1][j] != 'S'
		&& file[i + 1][j] != 'W' && file[i + 1][j] != 'E')
		return (1);
	if (file[i][j - 1] && file[i][j - 1] != '1' && file[i][j - 1] != '0'
		&& file[i][j - 1] != 'N' && file[i][j - 1] != 'S'
		&& file[i][j - 1] != 'W' && file[i][j - 1] != 'E')
		return (1);
	if (file[i][j + 1] && file[i][j + 1] != '1' && file[i][j + 1] != '0'
		&& file[i][j + 1] != 'N' && file[i][j + 1] != 'S'
		&& file[i][j + 1] != 'W' && file[i][j + 1] != 'E')
		return (1);
	return (0);
}

static int	check_plot(char **file, int i, int j)
{
	if (file[i][j] && file[i][j] != ' ' && file[i][j] != '1'
		&& file[i][j] != '0' && file[i][j] != 'N'
		&& file[i][j] != 'S' && file[i][j] != 'W'
		&& file[i][j] != 'E')
	{
		ft_putstr_fd("Error, wrong plot format\n", 2);
		exit(1);
	}
	else if (file[i][j] && file[i][j] == '0' && check_plot_zero(file, i, j))
	{
		ft_putstr_fd("Error, wrong map format\n", 2);
		exit(1);
	}
	return (0);
}

void	parsing_map(t_map *map, char **tab_file, int index, int size)
{
	int		j;
	int		k;

	k = 0;
	map->format_map = malloc(sizeof(char *) * size + 1);
	while (tab_file[index])
	{
		j = 0;
		if (tab_file[index][0] == '\n')
		{
			ft_putstr_fd("Error, wrong map format\n", 2);
			exit(1);
		}
		while (tab_file[index][j])
		{
			if (tab_file[index][j] == '\n')
				break ;
			check_plot(tab_file, index, j);
			j++;
		}
		map->format_map[k++] = tab_file[index++];
	}
	map->format_map[k] = NULL;
	map->format_map = reformatting_map(map->format_map);
}
