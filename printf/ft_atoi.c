/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:01:00 by dlian             #+#    #+#             */
/*   Updated: 2018/11/05 00:20:19 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		isminus;
	int		i;
	long	res;

	i = 0;
	res = 0;
	isminus = 0;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		isminus = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res ? (res * 10 + (str[i] - 48)) : str[i] - 48;
		if (res > 9223372036854775807)
			return (isminus ? 0 : -1);
		i++;
	}
	if (isminus)
		return (res * -1);
	return (res);
}
