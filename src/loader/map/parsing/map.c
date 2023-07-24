/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:19:15 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/24 14:00:47 by axcallet         ###   ########.fr       */
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
	int		j;
	int		max_len;
	char	**reformatting_map = NULL;

	i = 0;
	max_len = 0;
	while (template[i])
	{
		if ((int)ft_strlen(template[i]) > max_len)
			max_len = ft_strlen(template[i]);
		i++;
	}
	reformatting_map = malloc(sizeof(char*) * (i + 1));
	i = 0;
	while (template[i])
	{
		j = 0;
		reformatting_map[i] = malloc(sizeof(char) * (max_len + 1));
		while (template[i][j])
		{
			reformatting_map[i][j] = template[i][j];
			j++;
		}
		while (j != max_len)
			reformatting_map[i][j++] = ' ';
		reformatting_map[i][j] = '\0';
		i++;
	}
	reformatting_map[i] = NULL;
	free_tab(template);
	return (reformatting_map);
}

static int	check_plot_zero(char **file, int i, int j)
{
	if (file[i - 1][j] && file[i - 1][j] != '1' && file[i - 1][j] != '0'
		&& file[i - 1][j] != 'N' && file[i - 1][j] != 'S'
		&& file[i - 1][j] != 'W' && file[i - 1][j] != 'E')
		{
			printf("case au dessus\n");
			return (1);
		}
	if (file[i + 1][j] && file[i + 1][j] != '1' && file[i + 1][j] != '0'
		&& file[i + 1][j] != 'N' && file[i + 1][j] != 'S'
		&& file[i + 1][j] != 'W' && file[i + 1][j] != 'E')
		{
			printf("case en dessous\n");
			return (1);
		}
	if (file[i][j - 1] && file[i][j - 1] != '1' && file[i][j - 1] != '0'
		&& file[i][j - 1] != 'N' && file[i][j - 1] != 'S'
		&& file[i][j - 1] != 'W' && file[i][j - 1] != 'E')
		{
			printf("case avant\n");
			return (1);
		}
	if (file[i][j + 1] && file[i][j + 1] != '1' && file[i][j + 1] != '0'
		&& file[i][j + 1] != 'N' && file[i][j + 1] != 'S'
		&& file[i][j + 1] != 'W' && file[i][j + 1] != 'E')
		{
			printf("case apres\n");
			return (1);
		}
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
		printf("%d;%d\n", i , j);
		exit(1);
	}
	else if (file[i][j] && file[i][j] == '0' && check_plot_zero(file, i, j))
	{
		ft_putstr_fd("Error, wrong map format lol\n", 2);
		printf("%d %d\n", i, j);
		exit(1);
	}
	return (0);
}

void	parsing_map(t_map *map, char **tab_file, int index)
{
	int		j;
	int		k;

	k = 0;
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
				break;
			check_plot(tab_file, index, j);
			j++;
		}
		map->format_map[k] = tab_file[index];
		index++;
		k++;
	}
	map->format_map[k] = NULL;
	map->format_map = reformatting_map(map->format_map);
}
