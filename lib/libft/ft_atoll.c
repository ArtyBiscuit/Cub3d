/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:37:19 by arforgea          #+#    #+#             */
/*   Updated: 2023/01/02 18:37:44 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long long	ft_atoll(const char *nptr, int *flag)
{
	long long	nbr;
	long long	neg;

	nbr = 0;
	neg = 1;
	while (*nptr == 32 || (*nptr >= 8 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr *= 10;
		nbr += *nptr - 48;
		if (nbr * neg > 2147483647 || nbr * neg < -2147483648)
		{
			*flag = 1;
			return (0);
		}
		nptr++;
	}
	return (nbr * neg);
}
