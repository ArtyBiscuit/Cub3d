/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cardinal_points.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:17:37 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 19:17:38 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_cardinal_side(t_ray *ray)
{
	if (ray->side == 0 && ray->step_x == -1)
		return (NO);
	else if (ray->side == 1 && ray->step_y == -1)
		return (SO);
	else if (ray->side == 0 && ray->step_x == 1)
		return (WE);
	else if (ray->side == 1 && ray->step_y == 1)
		return (EA);
	return (0);
}
