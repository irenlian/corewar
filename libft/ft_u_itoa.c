/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 18:45:15 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/15 19:10:02 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static inline int		length(unsigned long long int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char					*ft_u_itoa(unsigned long long int n)
{
	char						*str;
	int							len;
	unsigned long long int		tmp;

	tmp = n;
	len = length(n);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = tmp % 10 + 48;
	while (tmp /= 10)
		str[--len] = tmp % 10 + 48;
	return (str);
}
