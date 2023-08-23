/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:27 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/01 15:44:54 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	rad_converter(float radian)
{
	return (radian * (180.0 / PI));
}

float	deg_converter(float degree)
{
	return (degree * (PI / 180.0));
}
