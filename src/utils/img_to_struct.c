/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_to_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <arforgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 19:19:08 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/20 20:07:58 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*img_to_struct(mlx_image_t *img)
{
	int			hex;
	int			i;
	int			j;
	uint8_t		*pix;
	t_texture	*texture;

	i = 0;
	j = 0;
	pix = img->pixels;
	texture = malloc(sizeof(t_texture));
	texture->pixels = malloc((int)(img->height * img->width) * sizeof(int));
	texture->size_x = img->width;
	texture->size_y = img->height;
	while (i < (int)((img->height * img->width) * 4))
	{
		hex = rgba_to_hex(pix[i], pix[i + 1], pix[i + 2], pix[i + 3]);
		texture->pixels[j] = hex;
		j += 1;
		i += 4;
	}
	return (texture);
}
