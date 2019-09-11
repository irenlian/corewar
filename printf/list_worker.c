/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_worker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:54:11 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 11:54:13 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params	*create_list(int start_index)
{
	t_params *list;

	list = (t_params *)malloc(sizeof(t_params));
	list->type = '\0';
	list->flags[0] = '\0';
	list->flags[1] = '\0';
	list->flags[2] = '\0';
	list->flags[3] = '\0';
	list->flags[4] = '\0';
	list->min_width = 0;
	list->precision = -1;
	list->modify[0] = '\0';
	list->modify[1] = '\0';
	list->modify[2] = '\0';
	list->start_index = start_index;
	list->last_index = -1;
	list->result = NULL;
	list->next = NULL;
	list->size = 0;
	return (list);
}

t_params	*push_list(t_params *start, t_params *node)
{
	t_params *tmp;

	tmp = start;
	if (!tmp)
		return (node);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (start);
}

void		free_list(t_params *list)
{
	t_params *tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		if (tmp->result)
			free(tmp->result);
		free(tmp);
	}
}
