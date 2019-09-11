/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:33:08 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 20:33:10 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*array;
	size_t	i;

	array = (char *)malloc(size);
	i = 0;
	if (array == NULL)
		return (NULL);
	while (i < size)
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}
