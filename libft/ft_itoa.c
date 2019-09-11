/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 21:20:51 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/07 22:02:28 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static inline int		length(long long int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char					*ft_itoa(long long int n)
{
	char				*str;
	int					len;
	long long int		tmp;

	tmp = n;
	len = length(n);
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = tmp % 10 + 48;
	while (tmp /= 10)
		str[--len] = tmp % 10 + 48;
	if (n < 0)
		str[0] = '-';
	return (str);
}
