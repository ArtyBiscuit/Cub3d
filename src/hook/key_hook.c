/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 17:31:49 by arforgea          #+#    #+#             */
/*   Updated: 2023/06/30 13:10:04 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/cub3d.h"
#include <stdio.h>

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_key	*key;

	key = param;
	key_action_press(keydata, key);
	key_action_release(keydata, key);
}
