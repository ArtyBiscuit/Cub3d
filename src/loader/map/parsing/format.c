/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axcallet <axcallet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:54:08 by axcallet          #+#    #+#             */
/*   Updated: 2023/07/27 16:45:37 by axcallet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture_path(char *arg, int i)
{
	if ((arg[i] || arg[i + 1]) && ((arg[i] != '.' || arg[i + 1] != '/')))
		return (1);
	while (arg[i] && !is_space(arg[i]))
		i++;
	if (arg[i])
		return (1);
	return (0);
}

static int	check_texture_format(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_isalpha(arg[i]))
	{
		if (!is_upper_case(arg[i++]))
			return (1);
		count++;
	}
	if (count != 2)
		return (1);
	if (!is_space(arg[i]))
		return (1);
	while (is_space(arg[i]))
	{
		if (arg[i + 1] == '\0')
			return (1);
		i++;
	}
	if (check_texture_path(arg, i))
		return (1);
	return (0);
}

static int	check_floor_ceiling_value(char *arg, int i)
{
	int	count_a;
	int	count_b;

	count_a = 0;
	while (count_a++ != 4)
	{
		count_b = 0;
		while (arg[i] != ',' && arg[i] != '\n')
		{
			if (!ft_isdigit(arg[i++]))
				return (1);
			if (++count_b > 3)
				return (1);
		}
		if (count_a == 3)
			break ;
		if (arg[i] != ',')
			return (1);
		i++;
		if (!ft_isdigit(arg[i]))
			return (1);
	}
	if (arg[i] != '\n')
		return (1);
	return (0);
}

static int	check_floor_ceiling_format(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (ft_isalpha(arg[i]))
	{
		if (!is_upper_case(arg[i++]))
			return (1);
		count++;
	}
	if (count != 1)
		return (1);
	if (!is_space(arg[i]))
		return (1);
	while (is_space(arg[i]))
	{
		if (arg[i + 1] == '\0')
			return (1);
		i++;
	}
	if (check_floor_ceiling_value(arg, i))
		return (1);
	return (0);
}

int	check_arg_format(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!is_upper_case(arg[i]))
		return (1);
	if (arg[i] == 'F' || arg[i] == 'C')
	{
		if (check_floor_ceiling_format(arg))
			return (1);
	}
	else
	{
		if (check_texture_format(arg))
			return (1);
	}
	return (0);
}
