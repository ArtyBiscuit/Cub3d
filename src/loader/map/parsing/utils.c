/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 10:16:26 by axcallet          #+#    #+#             */
/*   Updated: 2023/08/21 09:45:53 by axcallet         ###   ########.fr       */
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

int	check_arg_are_refile(t_map map)
{
	if (!map.texture_north || !map.texture_south || !map.texture_west
		|| !map.texture_east || !map.floor_color || !map.ceiling_color)
		return (1);
	return (0);
}
