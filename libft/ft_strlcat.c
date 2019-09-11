/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 19:10:32 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/06 19:47:56 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	char		*s;
	size_t		destlength;
	size_t		n;

	d = dst;
	s = (char *)src;
	n = size;
	while (*d != '\0' && n--)
		d++;
	destlength = d - dst;
	n = size - destlength;
	if (n == 0)
		return (destlength + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (destlength + (s - src));
}
