/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:16:31 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/07 10:05:03 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_file(char *file)
{
	int	fd;

	if (ft_strncmp(ft_substr(file, (ft_strlen(file) - 4), 4), ".cub", 5))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	close(fd);
	return (0);
}

void	check_arguments(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	if (check_file(argv[1]))
		exit(1);
}
