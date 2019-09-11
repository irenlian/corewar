/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:32:59 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 20:33:01 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*reslist;
	void	*contentcpy;

	reslist = (t_list*)malloc(sizeof(t_list));
	if (reslist == NULL)
		return (NULL);
	if (content == NULL)
	{
		reslist->content = NULL;
		reslist->content_size = 0;
		reslist->next = NULL;
		return (reslist);
	}
	contentcpy = ft_memalloc(content_size);
	if (!contentcpy)
		return (NULL);
	contentcpy = ft_memcpy(contentcpy, content, content_size);
	reslist->content = contentcpy;
	reslist->content_size = content_size;
	reslist->next = NULL;
	return (reslist);
}
