/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 09:45:07 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/24 10:29:05 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*refile_new_line(char **template, int max_len, int i)
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

int	map_len(char **tab_file, int i)
{
	int	size;

	size = 0;
	while (tab_file[i])
	{
		if (!ft_strncmp(tab_file[i], "NO", 2)
			|| !ft_strncmp(tab_file[i], "SO", 2)
			|| !ft_strncmp(tab_file[i], "WE", 2)
			|| !ft_strncmp(tab_file[i], "EA", 2)
			|| !ft_strncmp(tab_file[i], "F", 1)
			|| !ft_strncmp(tab_file[i], "C", 1))
		{
			ft_putstr_fd("Error: bad line\n", 2);
			exit(1);
		}
		i++;
		size++;
	}
	return (size);
}

void	set_player_dir(t_main *main, char c)
{
	if (c == 'N')
		player_rotate(main, (3 * PI) / 2);
	if (c == 'S')
		player_rotate(main, PI / 2);
	if (c == 'W')
		player_rotate(main, 0);
	if (c == 'E')
		player_rotate(main, PI);
}

void	set_player_pos(t_player *player, int i, int j)
{
	if (player->pos_x != 0.0 || player->pos_y != 0.0)
	{
		ft_putstr_fd("Error, wrong player pos\n", 2);
		exit(1);
	}
	player->pos_x = (float)j + 0.5;
	player->pos_y = (float)i + 0.5;
}
