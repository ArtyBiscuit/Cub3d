/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rad_converter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:34:27 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/29 18:34:52 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/cub3d.h"

float	rad_converter(float radian)
{
	return (radian * (180 / PI));
}

float	deg_converter(float degree)
{
	return (degree * (PI / 180));
}
