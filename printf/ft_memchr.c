/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:33:39 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 20:33:40 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*us;
	unsigned char	us2;

	i = 0;
	us = (unsigned char *)s;
	us2 = (unsigned char)c;
	while (i < n)
	{
		if (us[i] == us2)
			return ((void *)&us[i]);
		i++;
	}
	return (NULL);
}
