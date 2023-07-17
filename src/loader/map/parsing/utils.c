/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:16:26 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/14 09:32:29 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	is_upper_case(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

char	*add_spaces(char *line, int max_len)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	j = 0;
	new_line = malloc(sizeof(char) * (max_len + 1));
	while (line[j])
		new_line[i++] = line[j++];
	while (i <= max_len)
		new_line[i++] = '#';
	return (new_line);
}

int	check_arg_are_refile(t_map map)
{
	if (!map.texture_north || !map.texture_south || !map.texture_west
		|| !map.texture_east || !map.floor_color || !map.ceiling_color)
		return (1);
	return (0);
}
