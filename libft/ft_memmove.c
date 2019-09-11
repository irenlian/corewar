/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:51:56 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/06 19:49:22 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dest;
	char		*source;

	dest = (char*)dst;
	source = (char*)src;
	i = -1;
	if (dest > source)
		while ((int)--len > -1)
			dest[len] = source[len];
	else
		while (++i < len)
			dest[i] = source[i];
	return (dest);
}
