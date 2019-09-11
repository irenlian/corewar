/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_type.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:15:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/15 19:26:11 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char				*types_manager(va_list var, t_orgi *params)
{
	char	*str;

	if (params->l)
		str = itoa_base(va_arg(var, unsigned long), 16);
	else if (params->ll)
		str = itoa_base(va_arg(var, unsigned long long), 16);
	else if (params->h)
		str = u_itoa_base((unsigned short int)va_arg(var, int), 16);
	else if (params->hh)
		str = u_itoa_base((unsigned char)va_arg(var, int), 16);
	else
		str = itoa_base(va_arg(var, unsigned int), 16);
	return (str);
}

static char				*add_0x(char *str)
{
	char	*res;

	res = ft_strjoin("0X", str);
	free(str);
	return (res);
}

char					*x_type(va_list var, t_orgi *params)
{
	char	*str;
	int		i;
	char	fuck;

	i = -1;
	str = types_manager(var, params);
	fuck = (str[0] == '0') ? 1 : 0;
	str = implement_precision(str, params);
	str = (params->sharp && params->zero) ?
		implement_width(str, params->width - 2, params) : str;
	if (params->sharp && ft_strlen(str) > 0 && !fuck)
		str = add_0x(str);
	str = (!params->zero || !params->sharp) ?
		implement_width(str, params->width, params) : str;
	if (params->type == 'x')
		while (str[++i])
			if (str[i] > 64 && str[i] < 91)
				str[i] += 32;
	return (str);
}
