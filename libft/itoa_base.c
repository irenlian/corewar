/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 16:06:00 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/19 16:13:45 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		get_abs(int num)
{
	if (num == INT_MIN)
		return (-42);
	return (num < 0 ? num * -1 : num);
}

static int		count_size(long long int num, int base)
{
	int		size;

	if (num == 0)
		return (1);
	size = 0;
	while (num)
	{
		size++;
		num /= base;
	}
	return (size);
}

char			*itoa_base(long long int num, int base)
{
	char	*str;
	int		size;
	char	*res;
	int		minus;

	str = "0123456789ABCDEF";
	minus = 0;
	if (base < 2 || base > 16)
		return (0);
	if (num < 0 && base == 10)
		minus = 1;
	size = count_size(num, base) + minus;
	res = (char*)malloc(sizeof(char) * (size + 1));
	res[size] = '\0';
	while (size > minus)
	{
		res[size - 1] = str[get_abs(num % base)];
		num /= base;
		size--;
	}
	if (minus)
		res[0] = '-';
	return (res);
}
