/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:54:29 by pdemian           #+#    #+#             */
/*   Updated: 2018/10/27 18:20:05 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = b;
	while (len)
	{
		ptr[i] = c;
		i++;
		len--;
	}
	return (ptr);
}
