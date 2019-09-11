/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:40:48 by pdemian           #+#    #+#             */
/*   Updated: 2018/10/27 21:04:03 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (len)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
		{
			while (len--)
				dst[i++] = '\0';
			break ;
		}
		i++;
		len--;
	}
	return (dst);
}
