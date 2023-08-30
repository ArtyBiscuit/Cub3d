/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:19:15 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/30 14:38:17 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_plot_letter(char **file, int i, int j)
{
	if ((int)ft_strlen(file[i - 1]) < j || !file[i + 1]
		|| j == 0 || (int)ft_strlen(file[i]) == j)
		return (1);
	if (!file[i - 1][j] || (file[i - 1][j]
		&& file[i - 1][j] != '1' && file[i - 1][j] != '0'))
		return (1);
	if (!file[i + 1][j] || (file[i + 1][j]
		&& file[i + 1][j] != '1' && file[i + 1][j] != '0'))
		return (1);
	if (!file[i][j - 1] || (file[i][j - 1]
		&& file[i][j - 1] != '1' && file[i][j - 1] != '0'))
		return (1);
	if (!file[i][j + 1] || (file[i][j + 1]
		&& file[i][j + 1] != '1' && file[i][j + 1] != '0'))
		return (1);
	return (0);
}

static int	check_plot_zero(char **file, int i, int j)
{
	if ((int)ft_strlen(file[i - 1]) < j || !file[i + 1]
		|| j == 0 || (int)ft_strlen(file[i]) == j)
		return (1);
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

static int	check_plot(char **file, int index, int j)
{
	if (file[index][j] && (file[index][j] != ' ' && file[index][j] != '1'
		&& file[index][j] != '0' && file[index][j] != 'N'
		&& file[index][j] != 'S' && file[index][j] != 'W'
		&& file[index][j] != 'E'))
	{
		ft_putstr_fd("ERROR:\twrong plot format", 2);
		return (1);
	}
	else if (file[index][j] && file[index][j] == '0'
		&& check_plot_zero(file, index, j))
	{
		ft_putstr_fd("ERROR:\twrong map format\n", 2);
		return (1);
	}
	else if (file[index][j] && (file[index][j] == 'N' || file[index][j] == 'S'
		|| file[index][j] == 'W' || file[index][j] == 'E')
		&& check_plot_letter(file, index, j))
	{
		ft_putstr_fd("ERROR:\twrong map format\n", 2);
		return (1);
	}
	return (0);
}

static int	check_map(t_main *main, char **tab_file, int i)
{
	int	j;

	j = 0;
	while (tab_file[i][j] && tab_file[i][j] != '\n')
	{
		if (check_plot(tab_file, i, j))
			return (1);
		if (tab_file[i][j] && (tab_file[i][j] == 'N'
			|| tab_file[i][j] == 'S' || tab_file[i][j] == 'W'
			|| tab_file[i][j] == 'E'))
		{
			if (set_player_pos(&main->player, i, j))
				return (1);
			set_player_dir(main, tab_file[i][j]);
		}
		j++;
	}
	return (0);
}

int	parsing_map(t_main *main, char **tab_file, int index)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab_file[index])
	{
		main->map.format_map[j] = NULL;
		if (tab_file[index][0] == '\n')
		{
			ft_putstr_fd("ERROR:\twrong map format\n", 2);
			return (1);
		}
		if (check_map(main, tab_file, index))
			return (1);
		main->map.format_map[j++] = ft_strdup(tab_file[index++]);
		i++;
	}
	main->map.format_map[j] = NULL;
	free_tab(tab_file);
	main->map.format_map = reformatting_map(main->map.format_map);
	return (0);
}
