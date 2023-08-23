/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:57:40 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/23 10:34:04 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_collider_x(t_main *main, float pos_x, float pos_y)
{
	if (main->map.format_map[(int)pos_y][(int)pos_x] != '1')
		return (1);
	return (0);
}

int	check_collider_y(t_main *main, float pos_x, float pos_y)
{
	if (main->map.format_map[(int)pos_y][(int)pos_x] != '1')
		return (1);
	return (0);
}
