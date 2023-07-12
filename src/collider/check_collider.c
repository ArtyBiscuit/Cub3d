/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collider.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:57:40 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/29 17:58:08 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/cub3d.h"

int	check_collider_x(t_main *main, float pos_x, float pos_y)
{
	if (main->map_data.format_map[(int)pos_x][(int)pos_y] == 0)
		return (1);
	return (0);
}
int	check_collider_y(t_main *main, float pos_x, float pos_y)
{
	if (main->map_data.format_map[(int)pos_x][(int)pos_y] == 0)
		return (1);
	return (0);
}