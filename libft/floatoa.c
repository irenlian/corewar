/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floatoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 16:44:31 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/21 16:46:11 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int			round_int(long double base, long double prec)
{
	if (base > 0 && prec >= 0.5)
		return (base + 1);
	else if (base < 0 && prec <= -0.5)
		return (base + 1);
	else if (base > 0 && prec < 0.5)
		return (base);
	else if (base < 0 && prec > -0.5)
		return (base);
	return (base);
}

static void			cat(char *str, char *itoa_b)
{
	ft_strcat(str, itoa_b);
	free(itoa_b);
}

static void			make_the_end(char *str, char *itoa_b, int precision)
{
	int len;

	len = ft_strlen(itoa_b);
	while (len++ < precision)
		ft_strcat(str, "0");
}

char				*floatoa(long double nb, unsigned int precision)
{
	long long int	base;
	long double		prec;
	char			*str;
	char			*itoa_b;

	str = ft_strnew(30);
	if ((nb < 0 || nb == -0.0) && nb != 0.0)
	{
		ft_strcat(str, "-");
		nb = -nb;
	}
	base = (long long int)nb;
	prec = nb - base;
	base = (!precision) ? round_int(base, prec) : base;
	itoa_b = ft_itoa(base);
	cat(str, itoa_b);
	if (precision)
	{
		ft_strcat(str, ".");
		prec = prec * ft_power(10, precision);
		itoa_b = prec - (int)prec >= 0.5 ? ft_itoa(prec + 1) : ft_itoa(prec);
		make_the_end(str, itoa_b, precision);
		cat(str, itoa_b);
	}
	return (str);
}
