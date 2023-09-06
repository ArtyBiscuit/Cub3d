/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:00:44 by axcallet          #+#    #+#             */
/*   Updated: 2023/09/06 11:38:27 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture_format(char *str)
{
	int	i;

	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	if ((str[i] || str[i + 1]) && ((str[i] != '.' || str[i + 1] != '/')))
		return (1); 
}

static int	check_color_value(char *str)
{
	int		i;
	int		j;
	char	*buff

	i = 0;
	j = 0;
	while (ft_isdigit(str[i]))
		i++;
	if (i > 3 || i = 0)
		return (1);
	if (str[i + 1] != ' ' && str[i + 1] != ',' && str[i + 1] != '\n')
		return (1);
	buff = ft_substr(str, j, i);
	if (ft_atoi(buff) > 255 || ft_atoi(buff) < 0)
		return (1);
	return (0);
}

static int	check_color_format(char *str)
{
	int	i;

	i = 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (count < 3)
	{
		if (check_color_value(&str[i]))
			return (1);
		while (str[i] && ft_isdigit[str[i]])
			i++;
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] != ',')
			return (1);
		i++;
		if (str[i] && str[i] != ' ' && !ft_isdigit(str[i]))
			return (1);
		while (str[i] && str[i] == ' ')
			i++;
		count++;
	}
	return (0);
}

int check_arg_format(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (ft_strncmp("NO ", &str[i], 3) && ft_strncmp("SO ", &str[i], 3)
		&& ft_strncmp("WE ", &str[i], 3) && ft_strncmp("EA ", &str[i], 3)
		&& ft_strncmp("F ", &str[i], 2) && ft_strncmp("C ", &str[i], 2))
		return (1);
	if (!ft_strncmp("NO ", &str[i], 3) || !ft_strncmp("SO ", &str[i], 3)
		|| !ft_strncmp("WE ", &str[i], 3) || !ft_strncmp("EA ", &str[i], 3))
	{
		if (check_texture_format(&str[i]))
			return (1);
	}
	else if (!ft_strncmp("F ", &str[i], 2) || !ft_strncmp("C ", &str[i], 2))
	{
		if (check_color_format(&str[i]))
			return (1);
	}
	return (0);
}