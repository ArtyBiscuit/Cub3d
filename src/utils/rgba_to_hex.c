/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgba_to_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:19:34 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 19:58:48 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgba_to_hex(int r, int g, int b, int a)
{
	int	h;
	int	nr;
	int	ng;
	int	nb;

	nr = (r & 0xff) << 24;
	ng = (g & 0xff) << 16;
	nb = (b & 0xff) << 8;
	h = nr + ng + nb + (a & 0xff);
	return (h);
}
