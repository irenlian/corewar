/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:50:43 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/15 20:06:45 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char				*u_type(t_orgi *params, va_list var)
{
	char	*str;

	if (params->l)
		str = ft_itoa(va_arg(var, unsigned long));
	else if (params->ll)
		str = ft_itoa(va_arg(var, unsigned long long));
	else if (params->h)
		str = ft_u_itoa((unsigned short int)va_arg(var, int));
	else if (params->hh)
		str = ft_u_itoa((unsigned char)va_arg(var, int));
	else
		str = ft_itoa(va_arg(var, unsigned int));
	str = implement_width(str, params->width, params);
	str = implement_precision(str, params);
	return (str);
}

char				*o_type(va_list var, t_orgi *params)
{
	char	*str;

	if (params->l)
		str = itoa_base(va_arg(var, unsigned long), 8);
	else if (params->ll)
		str = itoa_base(va_arg(var, unsigned long long), 8);
	else if (params->h)
		str = itoa_base((unsigned short int)va_arg(var, int), 8);
	else if (params->hh)
		str = itoa_base((unsigned char)va_arg(var, int), 8);
	else
		str = itoa_base(va_arg(var, int), 8);
	if (params->sharp && str[ft_strlen(str) - 1] != '0')
		str = paste_start(str, '0');
	str = implement_precision(str, params);
	str = implement_width(str, params->width, params);
	return (str);
}

char				*d_type(va_list var, t_orgi *params)
{
	char				*str;
	long long int		nb;

	if (params->l)
		nb = va_arg(var, long int);
	else if (params->ll)
		nb = va_arg(var, long long int);
	else if (params->h)
		nb = (short int)va_arg(var, int);
	else if (params->hh)
		nb = (signed char)va_arg(var, int);
	else
		nb = va_arg(var, int);
	if (nb == 0 && params->plus == '+')
		str = "+0";
	str = (nb > -1) ? ft_itoa(nb) : ft_itoa(-nb);
	str = implement_precision(str, params);
	str = implement_sign(str, nb, params);
	str = implement_width(str, params->width, params);
	return (str);
}

char				*s_type(char *str, t_orgi *params)
{
	if (!str)
		str = ft_strdup("(null)");
	else if (!str && params->dot)
		str = ft_strndup("(null)", params->precision);
	else if (params->dot)
		str = ft_strndup(str, params->precision);
	else
		str = ft_strdup(str);
	str = implement_width(str, params->width, params);
	return (str);
}

char				*c_type(char c, t_orgi *params)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * 2);
	str[1] = '\0';
	str[0] = c;
	str = implement_width(str, params->width, params);
	return (str);
}
