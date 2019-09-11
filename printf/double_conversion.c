/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:40:09 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 11:40:14 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reverse(char *str, int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int		inttostr(long x, char *str, int d)
{
	int i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

int		get_fsize(long double n, t_params *list)
{
	long len;

	len = 0;
	n = (long)n;
	while (n)
	{
		len++;
		n /= 10;
	}
	if (list->precision == -1)
		len += 7;
	else if (list->precision > 0)
		len += (list->precision + 1);
	else if (list->precision == 0 && list->flags[1] == '#')
		len++;
	return (len);
}

char	*ft_ftoa(long double n, t_params *list)
{
	long		ipart;
	long double	fpart;
	int			i;
	char		*res;
	int			aftr;

	res = (char *)malloc(sizeof(char) * get_fsize(n, list) + sizeof(char));
	aftr = (list->precision == 0) ? 0 : 6;
	aftr = (list->precision != -1) ? list->precision : 6;
	ipart = (long)n;
	fpart = n - (long double)ipart;
	if (aftr == 0 && ((long)(fpart * ft_pow(10, (aftr + 1)))) % 10 > 4)
		ipart++;
	i = inttostr(ipart, res, 0);
	if (list->flags[1] == '#' || aftr != 0)
		res[i] = '.';
	if (aftr != 0)
	{
		fpart = fpart * ft_pow(10, (aftr));
		if (((long)(fpart * ft_pow(10, (aftr + 1)))) % 10 > 4)
			fpart++;
		inttostr((int)fpart, res + i + 1, aftr);
	}
	return (res);
}

void	set_float(t_params *list, long double num)
{
	int		len;
	char	*result;
	char	*strnum;

	strnum = ft_ftoa(num, list);
	len = ft_strlen(strnum);
	result = set_width(get_resultsize((long long)num, len, list, strnum), ' ');
	if (list->flags[2] == '-')
		fill_result(((num >= 0) ? 1 : 0), list, result, strnum);
	else
		revers_fill_result(((num >= 0) ? 1 : 0), list, result, strnum);
	free(strnum);
	list->result = result;
}
