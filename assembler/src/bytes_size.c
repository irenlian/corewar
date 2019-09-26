/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bytes_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:57:31 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:57:34 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int	get_size_arg(char *arg, t_command *com)
{
	if (!arg)
		return (0);
	if (arg[0] == 'r')
		return (1);
	if (arg[0] == DIRECT_CHAR)
		return (com->dir_size);
	return (2);
}

int	count_size_to_label(t_list *code_list, t_code *sicked)
{
	int		size;
	t_code	*curr_code;

	size = 0;
	while (code_list)
	{
		curr_code = ((t_code *)code_list->content);
		if (curr_code->id == sicked->id)
			break ;
		size += curr_code->byte_size;
		code_list = code_list->next;
	}
	return (size);
}

int	get_byte_size_to_marked(t_list *curr_code, t_list *marked_code)
{
	int		size;
	t_code	*c_code;
	t_code	*m_code;

	c_code = ((t_code *)curr_code->content);
	m_code = ((t_code *)marked_code->content);
	if (c_code->id > m_code->id)
		size = count_size_to_label(marked_code, c_code) * -1;
	else
		size = count_size_to_label(curr_code, m_code);
	return (size);
}
