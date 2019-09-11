/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 18:08:28 by pdemian           #+#    #+#             */
/*   Updated: 2019/04/15 19:09:13 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strrew(char *src)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	str = ft_strnew(len);
	len--;
	while (len > -1)
	{
		str[i] = src[len];
		i++;
		len--;
	}
	return (str);
}
