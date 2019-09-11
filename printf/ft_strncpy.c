/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 21:51:34 by dlian             #+#    #+#             */
/*   Updated: 2018/11/05 00:23:33 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < (int)len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
		dst[i++] = '\0';
	return (dst);
}
