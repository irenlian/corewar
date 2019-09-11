/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:38:20 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 20:38:21 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	array = (char *)malloc(sizeof(char) * size + 1);
	if (array == NULL)
		return (NULL);
	while (i < size + 1)
	{
		array[i] = '\0';
		i++;
	}
	return (array);
}
