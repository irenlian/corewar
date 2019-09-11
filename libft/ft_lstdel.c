/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:21:03 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/07 17:31:57 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp;

	if (!alst || !*alst)
		return ;
	list = *alst;
	while (list)
	{
		tmp = list->next;
		del(list, list->content_size);
		list = tmp;
	}
	*alst = NULL;
}
