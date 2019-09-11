/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:36:52 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/07 21:07:49 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t x;
	size_t j;

	if (!(*little))
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		x = 0;
		j = i;
		while (big[j] == little[x] && j < len)
		{
			if (little[x + 1] == '\0')
				return ((char*)big + i);
			x++;
			j++;
		}
		i++;
	}
	return (NULL);
}
