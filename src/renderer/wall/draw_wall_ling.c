/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_ling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:13:25 by arforgea          #+#    #+#             */
/*   Updated: 2023/08/07 10:29:14 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int get_start(t_wall_line *line)
{
    int start;

    if (line->start < 0)
        start = 0;
    else
        start = line->start;
    return (start);
}

int get_end(t_wall_line *line)
{
    int end;

    if (line->end > HEIGHT)
        end = HEIGHT;
    else
        end = line->end;
    return (end);
}

int get_y_pixel(int start, t_wall_line line)
{
    float a;

    a = (float)(start - line.start) / line.wall_height;
    return (a * line.texture->size_x);
}

void    draw_wall_line(t_main *main, t_wall_line *line)
{
    int     y;
    int     x;
    int     start;
    int     color;
    float   fog_dist;

    x = get_line_gap(line->texture, line->ray, main);
    start = get_start(line);
    fog_dist = line->line_dist / 15;
    while (start < get_end(line))
    {
        if (start >= 0 && start < HEIGHT -1)
        {
            y = get_y_pixel(start, *line);
            color = line->texture->pixels[x + y * line->texture->size_y];
            if (1 == 1)
                color = set_wall_fog(color, fog_dist, 0xFF);
            mlx_put_pixel(main->mlx_data.img, line->ray->ray_id, start, color);
        }
        start++;
    }
}
