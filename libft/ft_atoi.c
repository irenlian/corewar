/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:50:44 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/22 14:52:46 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int						ft_atoi(const char *str)
{
	int					minus;
	unsigned long		r;

	r = 0;
	minus = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		minus = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		r = r * 10 + *str - 48;
		if (r >= FT_LONG_MAX && minus == 1)
			return (-1);
		else if (r > FT_LONG_MAX && minus == -1)
			return (0);
		str++;
	}
	r *= minus;
	return (r);
}
