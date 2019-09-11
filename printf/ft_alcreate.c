/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alcreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 23:45:26 by dlian             #+#    #+#             */
/*   Updated: 2018/11/10 23:45:28 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_alist	*ft_alcreate(size_t byte)
{
	t_alist *array;

	array = (t_alist*)malloc(sizeof(t_alist));
	array->size = 0;
	array->data = NULL;
	array->byte = byte;
	return (array);
}
