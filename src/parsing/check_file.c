/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:16:31 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/17 14:22:27 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file(char *file)
{
	int	fd;

	if (ft_strncmp(ft_substr(file, (ft_strlen(file) - 4), 4), ".cub", 5))
	{
		ft_putstr_fd("Error: open: bad extension\n", 2);
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error: open: map file not found or not authorized\n", 2);
		return (1);
	}
	close(fd);
	return (0);
}

void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error: wrong number of arguments\n", 2);
		exit(1);
	}
	if (check_file(argv[1]))
		exit(1);
}
