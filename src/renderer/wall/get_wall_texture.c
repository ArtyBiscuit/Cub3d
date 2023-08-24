/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wall_texture.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:14:05 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/24 17:22:14 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*get_wall_texture(t_main *main, t_ray *ray)
{
	int	cord;

	cord = get_cardinal_side(ray);
	if (cord == NO)
		return (main->wall_texture[0]);
	if (cord == SO)
		return (main->wall_texture[1]);
	if (cord == WE)
		return (main->wall_texture[3]);
	if (cord == EA)
		return (main->wall_texture[2]);
	return (main->wall_texture[0]);
}
