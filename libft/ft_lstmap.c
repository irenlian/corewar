/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:53:51 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/07 18:11:36 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	new = tmp;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (!tmp->next)
			return (NULL);
		tmp = tmp->next;
	}
	return (new);
}
