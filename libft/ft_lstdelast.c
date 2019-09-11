/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:56:48 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/12 15:56:50 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdelast(t_list **alst)
{
	t_list	*list;
	t_list	*tmp;

	if (!(*alst))
		return ;
	list = *alst;
	if (!list->next)
	{
		ft_lstdel(alst, ft_lstfree);
		return ;
	}
	while (list->next->next)
		list = list->next;
	tmp = list;
	list = list->next;
	free(list->content);
	free(list);
	list = NULL;
	tmp->next = NULL;
}
