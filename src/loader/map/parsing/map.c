/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:19:15 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/18 13:29:13 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static int	strlen_map(char **file)
// {
// 	int	i;
// 	int	len;

// 	i = 8;
// 	len = 0;
// 	while (file[i])
// 	{
// 		i++;
// 		len++;
// 	}
// 	return (len);
// }

static char	**reformatting_map(char **template)
{
	int		i;
	size_t	max_len;

	i = 0;
	max_len = 0;
	while (template[i])
	{
		if (ft_strlen(template[i]) > max_len)
			max_len = ft_strlen(template[i]);
		i++;
	}
	i = 0;
	while (template[i])
	{
		if (ft_strlen(template[i]) < max_len)
			template[i] = add_spaces(template[i], max_len);
		i++;
	}
	return (template);
}

static int	check_plot_zero(char **file, int x, int y)
{
	if (file[x - 1][y] && file[x - 1][y] != '1' && file[x - 1][y] != '0'
		&& file[x - 1][y] != 'N' && file[x - 1][y] != 'S'
		&& file[x - 1][y] != 'W' && file[x - 1][y] != 'E')
		return (1);
	if (file[x + 1][y] && file[x + 1][y] != '1' && file[x + 1][y] != '0'
		&& file[x + 1][y] != 'N' && file[x + 1][y] != 'S'
		&& file[x + 1][y] != 'W' && file[x + 1][y] != 'E')
		return (1);
	if (file[x][y - 1] && file[x][y - 1] != '1' && file[x][y - 1] != '0'
		&& file[x][y - 1] != 'N' && file[x][y - 1] != 'S'
		&& file[x][y - 1] != 'W' && file[x][y - 1] != 'E')
		return (1);
	if (file[x][y + 1] && file[x][y + 1] != '1' && file[x][y + 1] != '0'
		&& file[x][y + 1] != 'N' && file[x][y + 1] != 'S'
		&& file[x][y + 1] != 'W' && file[x][y + 1] != 'E')
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
	else if (file[i][j] && file[i][j] == '0' && check_plot_zero(file, j, i))
	{
		ft_putstr_fd("Error, wrong map format lol \n", 2);
		exit(1);
	}
	return (0);
}

void	parsing_map(t_map *map, char **tab_file)
{
	int		i;
	int		j;
	int		k;

	i = 7;
	k = 0;
	while (tab_file[i++])
	{
		j = 0;
		if (tab_file[i][0] == '\n')
		{
			ft_putstr_fd("Error, wrong map format\n", 2);
			exit(1);
		}
		while (tab_file[i][j])
		{
			check_plot(tab_file, i, j);
			map->format_map[k] = tab_file[i];
			j++;
		}
	}
	map->format_map = reformatting_map(map->format_map);
}
