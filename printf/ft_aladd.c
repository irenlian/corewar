/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aladd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:34:44 by dlian             #+#    #+#             */
/*   Updated: 2018/11/10 23:34:50 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alist	*ft_aladd(t_alist *list, void *elem)
{
	void	*data;
	size_t	i;

	i = 0;
	data = ft_memalloc(list->size * list->byte + list->byte);
	data = ft_memcpy(data, list->data, list->size * list->byte);
	while (i < list->byte)
	{
		((unsigned char*)data)[list->byte * list->size + i] =
		((unsigned char*)elem)[i];
		i++;
	}
	list->size++;
	free(list->data);
	list->data = data;
	return (list);
}
