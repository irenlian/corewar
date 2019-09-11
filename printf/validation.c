/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:06:15 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 12:06:17 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	validate_ui(t_params *list)
{
	if (list->flags[2] == '-')
		list->flags[0] = '\0';
	list->flags[3] = '\0';
	list->flags[4] = '\0';
	if (list->type == 'u')
		list->flags[1] = '\0';
}

void	validate_i(t_params *list)
{
	if (list->flags[2] == '-')
		list->flags[0] = '\0';
	if (list->flags[3] == '+')
		list->flags[4] = '\0';
}

void	validate_str(t_params *list)
{
	list->flags[4] = '\0';
	if (list->flags[2] == '-')
		list->flags[0] = '\0';
	if (list->type == 'p')
		list->flags[3] = '\0';
}

void	validate_fl(t_params *list)
{
	if (list->flags[2] == '-')
		list->flags[0] = '\0';
	if (list->flags[3] == '+')
		list->flags[4] = '\0';
}

void	validate(t_params *list)
{
	while (list)
	{
		if (list->type == 'o' || list->type == 'u' ||
			list->type == 'x' || list->type == 'X')
			validate_ui(list);
		else if (list->type == 'i' || list->type == 'd')
			validate_i(list);
		else if (list->type == 's' || list->type == 'p' ||
			list->type == 'c' || list->type == '%')
			validate_str(list);
		else if (list->type == 'f')
			validate_fl(list);
		list = list->next;
	}
}
