/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:04:12 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 12:04:14 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_string(va_list ap, t_params *list)
{
	char	*s;
	char	c;

	if (list->type == 's')
	{
		s = va_arg(ap, char *);
		if (!s)
			put_str(list, "(null)");
		else
			put_str(list, s);
	}
	else if (list->type == '%')
		put_str(list, "%");
	else if (list->type == 'c')
	{
		c = (char)va_arg(ap, int);
		if (!c)
			put_char(list, 0);
		else
			put_char(list, c);
	}
}

void	parse_numbers(va_list ap, t_params *list)
{
	char	c;
	short	s;

	if (list->modify[0] == 'l' && list->modify[1] == 'l')
		put_ll(list, va_arg(ap, long long));
	else if (list->modify[0] == 'l')
		put_ll(list, (long long)(va_arg(ap, long)));
	else if (list->modify[0] == 'h' && list->modify[1] == 'h')
	{
		c = (char)va_arg(ap, int);
		put_ll(list, (long long)c);
	}
	else if (list->modify[0] == 'h')
	{
		s = (short)va_arg(ap, int);
		put_ll(list, (long long)s);
	}
	else
		put_ll(list, (long long)(va_arg(ap, int)));
}

void	parse_unsi(va_list ap, t_params *list)
{
	unsigned char	c;
	unsigned short	s;

	if (list->modify[0] == 'l' && list->modify[1] == 'l')
		put_ull(list, va_arg(ap, unsigned long long));
	else if (list->modify[0] == 'l')
		put_ull(list, (unsigned long long)(va_arg(ap, unsigned long)));
	else if (list->modify[0] == 'h' && list->modify[1] == 'h')
	{
		c = (char)va_arg(ap, int);
		put_ull(list, (unsigned long long)c);
	}
	else if (list->modify[0] == 'h')
	{
		s = (short)va_arg(ap, int);
		put_ull(list, (unsigned long long)s);
	}
	else
		put_ull(list, (unsigned long long)va_arg(ap, unsigned int));
}

void	parse_double(va_list ap, t_params *list)
{
	if (list->modify[0] == 'L')
		set_float(list, (va_arg(ap, double)));
	else
		set_float(list, (long double)((va_arg(ap, double))));
}
