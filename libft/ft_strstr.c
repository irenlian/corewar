/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 13:51:26 by pdemian           #+#    #+#             */
/*   Updated: 2018/10/29 17:14:24 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	x;
	size_t	i;

	i = 0;
	if (*big == '\0' && *little == '\0')
		return ((char*)big);
	if (!(ft_strlen(little)))
		return ((char*)big);
	while (big[i])
	{
		x = 0;
		while (little[x] == big[i + x])
		{
			if (little[x + 1] == '\0')
				return ((char*)big + i);
			x++;
		}
		i++;
	}
	return (0);
}
