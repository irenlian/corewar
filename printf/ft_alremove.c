/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alremove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:36:17 by dlian             #+#    #+#             */
/*   Updated: 2018/11/10 23:36:19 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alist	*ft_alremove(t_alist *list, size_t rmi)
{
	void	*data;
	size_t	i;

	i = 0;
	if (list->size <= i)
		return (list);
	data = ft_memalloc(list->size * list->byte - list->byte);
	while (i < list->byte * (list->size))
	{
		if (i < rmi * list->byte)
			((unsigned char*)data)[i] = ((unsigned char*)list->data)[i];
		else if (i >= rmi * list->byte + list->byte)
			((unsigned char*)data)[i - list->byte] =
		((unsigned char*)list->data)[i];
		i++;
	}
	list->size--;
	free(list->data);
	list->data = data;
	return (list);
}
