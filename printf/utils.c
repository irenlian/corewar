/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:03:06 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 12:03:08 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_numsize(long long num, int precision, char type)
{
	int					len;
	int					num_type;
	unsigned long long	tmp;

	tmp = num;
	len = 0;
	if (!num)
		len = 1;
	num_type = 10;
	if (type == 'o')
		num_type = 8;
	else if (type == 'x' || type == 'X' || type == 'p')
		num_type = 16;
	while (num)
	{
		len++;
		num /= num_type;
	}
	len = precision > len ? precision : len;
	if (!precision && !tmp)
		return (precision);
	return (len);
}

int		get_resultsize(long long num, int len, t_params *list, char *strnum)
{
	if (list->type == 'p')
		len += 2;
	if (list->flags[1] == '#' && (list->type == 'x' ||
		list->type == 'X') && num != 0)
		len += 2;
	if (num < 0 || list->flags[3] == '+')
		len++;
	if (list->flags[4] == ' ' && list->flags[3] != '+' && num >= 0)
		len++;
	if (list->flags[1] == '#' && list->type == 'o' &&
		strnum[0] != '0' && (list->min_width <= len ||
			list->flags[0] != '0' || list->flags[2] == '-'))
		len++;
	len = list->min_width > len ? list->min_width : len;
	return (len);
}

char	*set_width(int size, char c)
{
	char	*array;
	int		i;

	array = (char *)malloc(sizeof(char) * size + sizeof(char));
	i = 0;
	if (array == NULL)
		return (NULL);
	while (i < size)
	{
		array[i] = c;
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_itoal(long long n, int len, char type)
{
	char	*result;
	int		num_type;
	int		tmp;

	num_type = (type == 'o') ? 8 : 10;
	num_type = (type == 'x' || type == 'X' || type == 'p') ? 16 : 10;
	result = (char *)malloc(sizeof(char) * len + sizeof(char));
	result[len] = '\0';
	while (n)
	{
		tmp = n % num_type;
		if (tmp < 0)
			tmp *= -1;
		if (tmp > 9 && (type == 'x' || type == 'p'))
			result[--len] = tmp + 87;
		else if (tmp > 9 && type == 'X')
			result[--len] = tmp + 55;
		else
			result[--len] = tmp + '0';
		n = n / num_type;
	}
	while (len > 0)
		result[--len] = '0';
	return (result);
}

int		ft_pow(int n, int to)
{
	int res;

	res = 0;
	while (to > 0)
	{
		res = res ? res * n : n;
		to--;
	}
	return (res);
}
