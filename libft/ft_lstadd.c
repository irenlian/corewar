/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:32:25 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/13 02:20:49 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (!alst)
	{
		*alst = new;
		new->next = NULL;
	}
	new->next = *alst;
	*alst = new;
}
