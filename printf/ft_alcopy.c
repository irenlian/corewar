/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alcopy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:35:29 by dlian             #+#    #+#             */
/*   Updated: 2018/11/10 23:35:31 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alist	*ft_alcopy(t_alist *list)
{
	t_alist	*copy;
	int		i;

	i = 0;
	copy = ft_alcreate(list->byte);
	copy->size = list->size;
	copy->data = ft_memalloc(list->size * list->byte);
	copy->data = ft_memcpy(copy->data, list->data, list->size * list->byte);
	copy->byte = list->byte;
	return (list);
}
