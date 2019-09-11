/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:31:53 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 23:28:27 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*createzero(void)
{
	char	*res;

	if (!(res = ft_strnew(1)))
		return (NULL);
	res[0] = '0';
	return (res);
}

static int		get_size(long i)
{
	int		size;

	size = 0;
	while (i != 0)
	{
		size++;
		i = i / 10;
	}
	return (size);
}

static int		ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		isminus;
	int		size;

	size = 0;
	isminus = 0;
	if (n == 0)
		return (createzero());
	if (n < 0)
	{
		isminus = 1;
		size++;
		n *= -1;
	}
	size += get_size(n);
	if (!(res = ft_strnew(size)))
		return (NULL);
	while (n != 0)
	{
		res[--size] = ft_abs(n % 10) + 48;
		n = n / 10;
	}
	if (isminus)
		res[--size] = '-';
	return (res);
}
