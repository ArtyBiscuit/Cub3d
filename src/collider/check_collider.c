/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:57:40 by arforgea          #+#    #+#             */
/*   Updated: 2023/07/31 16:05:17 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_collider_x(t_main *main, float pos_x, float pos_y)
{
	if (main->map.format_map[(int)pos_y][(int)pos_x] == '0')
		return (1);
	return (0);
}
int	check_collider_y(t_main *main, float pos_x, float pos_y)
{
	if (main->map.format_map[(int)pos_y][(int)pos_x] == '0')
		return (1);
	return (0);
}
