/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:42:36 by pdemian           #+#    #+#             */
/*   Updated: 2018/10/29 14:49:32 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (s1) ? (unsigned char*)s1 : NULL;
	str2 = (s2) ? (unsigned char*)s2 : NULL;
	while (*str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
