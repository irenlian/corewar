/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:14:02 by pdemian           #+#    #+#             */
/*   Updated: 2018/10/29 14:25:35 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	*str;

	ptr = NULL;
	str = (char*)s;
	while (*str)
	{
		if (*str == (char)c)
			ptr = str;
		str++;
	}
	if (*str == (char)c)
		return (str);
	return (ptr);
}
