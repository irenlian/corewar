/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:46:23 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 11:46:25 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_ullresultsize(int len, t_params *list, char *strnum)
{
	if (list->flags[1] == '#' && (list->type == 'x' || list->type == 'X'))
		len += 2;
	if (list->flags[1] == '#' && list->type == 'o' && strnum[0] != '0' &&
		(list->min_width <= len || list->flags[0] != '0' ||
		list->flags[2] == '-'))
		len++;
	len = list->min_width > len ? list->min_width : len;
	return (len);
}

int		get_ullsize(unsigned long long num, int precision, char type)
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

char	*ft_ullitoal(unsigned long long n, int len, char type)
{
	char	*result;
	int		num_type;
	int		tmp;

	num_type = (type == 'o') ? 8 : 10;
	num_type = (type == 'x' || type == 'X' || type == 'p') ? 16 : num_type;
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

void	put_ull(t_params *list, unsigned long long num)
{
	int		len;
	char	*result;
	char	*strnum;

	if ((list->type == 'x' || list->type == 'X') && num == 0)
		list->flags[1] = '\0';
	len = get_ullsize(num, list->precision, list->type);
	strnum = ft_ullitoal(num, len, list->type);
	result = set_width(get_ullresultsize(len, list, strnum), ' ');
	if (list->flags[2] == '-')
		fill_result(1, list, result, strnum);
	else
		revers_fill_result(1, list, result, strnum);
	free(strnum);
	list->result = result;
	list->size = ft_strlen(result);
}
