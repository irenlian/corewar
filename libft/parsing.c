/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 13:52:38 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/15 20:31:05 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void			color_this(va_list var)
{
	char	*color_code;

	color_code = va_arg(var, char*);
	if (ft_strequ(color_code, RED) ||
		ft_strequ(color_code, GREEN) ||
		ft_strequ(color_code, YELLOW) ||
		ft_strequ(color_code, BLUE) ||
		ft_strequ(color_code, MAGENTA) ||
		ft_strequ(color_code, CYAN) ||
		ft_strequ(color_code, WHITE) ||
		ft_strequ(color_code, B_RED) ||
		ft_strequ(color_code, B_GREEN) ||
		ft_strequ(color_code, B_YELLOW) ||
		ft_strequ(color_code, B_BLUE) ||
		ft_strequ(color_code, B_MAGENTA) ||
		ft_strequ(color_code, B_CYAN) ||
		ft_strequ(color_code, B_WHITE) ||
		ft_strequ(color_code, EOC))
		ft_putstr(color_code);
}

static char			*get_str(va_list var, t_orgi *params)
{
	char	*res;

	if (params->type == '%')
		res = percent_manages(params);
	else if (params->type == 'c')
		res = c_type(va_arg(var, int), params);
	else if (params->type == 's')
		res = s_type(va_arg(var, char*), params);
	else if (params->type == 'd' || params->type == 'i')
		res = d_type(var, params);
	else if (params->type == 'o')
		res = o_type(var, params);
	else if (params->type == 'u')
		res = u_type(params, var);
	else if (params->type == 'x' || params->type == 'X')
		res = x_type(var, params);
	else if (params->type == 'p')
		res = p_type(var, params);
	else if (params->type == 'f')
		res = f_type(var, params);
	else
		return (0);
	return (res);
}

void				get_width(const char *format, int nargs, t_orgi *params)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 0;
	str = ft_strndup(format, nargs);
	tmp = str;
	free(str);
	while (i < nargs)
	{
		if (tmp[i] > 48 && tmp[i] < 58 && tmp[i - 1] != '.')
		{
			params->width = ft_atoi(tmp + i);
			break ;
		}
		i++;
	}
}

void				get_modifier(const char *format, int nargs, t_orgi *params)
{
	if (format[nargs - 2] == 'h')
	{
		if (format[nargs - 3] != 'h')
			params->h = 1;
		else if (format[nargs - 3] == 'h')
			params->hh = 1;
	}
	else if (format[nargs - 2] == 'l')
	{
		if (format[nargs - 3] != 'l')
			params->l = 1;
		else if (format[nargs - 3] == 'l')
			params->ll = 1;
	}
	else if (format[nargs - 2] == 'L')
		params->bigl = 1;
}

int					parse_this(va_list var, t_orgi *params)
{
	char	*res;
	int		len;

	if (params->type == 't')
	{
		color_this(var);
		return (0);
	}
	res = get_str(var, params);
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	return (len);
}
