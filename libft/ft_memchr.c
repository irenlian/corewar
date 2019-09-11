/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 19:46:50 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/07 20:23:54 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char *str;

	str = (char*)s;
	while (n)
	{
		if (*str == (char)c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
