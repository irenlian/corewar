/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:55:48 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/15 19:37:05 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void				get_flags(const char *format, int nargs, t_orgi *params)
{
	int	i;

	i = -1;
	while (++i < nargs && (format[i] < '1' || format[i] > '9'))
	{
		if (format[i] == '#')
			params->sharp = 1;
		else if (format[i] == '0')
			params->zero = 1;
		else if (format[i] == '-')
			params->minus = 1;
		else if (format[i] == '+')
			params->plus = 1;
		else if (format[i] == ' ')
			params->space = 1;
	}
}

static void				check_precision(const char *format,
		int nargs, t_orgi *params)
{
	while (--nargs > -1)
	{
		if (format[nargs] == '.')
		{
			params->dot = 'H';
			params->precision = ft_atoi(format + 1 + nargs);
			return ;
		}
	}
}

static void				save_this(const char *format, int nargs, t_orgi *params)
{
	ft_bzero(params, sizeof(t_orgi));
	params->type = format[nargs - 1];
	get_flags(format, nargs, params);
	check_precision(format, nargs, params);
	get_width(format, nargs, params);
	get_modifier(format, nargs, params);
}

static int				count_args(const char *format)
{
	char	*all_possible;
	int		i;

	i = 0;
	all_possible = "cspdio%ufxXt";
	while (format[i])
	{
		if ((ft_strchr(all_possible, format[i])))
			return (i + 1);
		i++;
	}
	return (0);
}

int						ft_printf(const char *format, ...)
{
	va_list		args;
	int			nargs;
	t_orgi		params;
	int			done;

	done = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			done++;
		}
		else
		{
			format++;
			nargs = count_args(format);
			save_this(format, nargs, &params);
			done += parse_this(args, &params);
			format += (params.type == 't') ? 0 : nargs - 1;
		}
		format++;
	}
	return (done);
}
