/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:21:05 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/15 14:22:07 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/cub3d.h"
#include <fcntl.h>
#include <unistd.h>

t_map	*get_map_size(t_map *map_struct, char *path)
{
	int fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error get_map_size (OPEN-ERROR)", 2);
		return (NULL);
	}
	while ()
	{
	
	}
	close(fd);
	return 
}
