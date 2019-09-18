/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:22:32 by pdemian           #+#    #+#             */
/*   Updated: 2019/09/13 16:22:32 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Save asm code in t_code structure
*/
void		parse_code(t_champ *champ, t_code *code)
{
    int			start;
	int			end;
    t_list		*list;
	char		*line;

	list = champ->asm_code;
	while (list)
	{
		line = (char*)list->content;
		end = 0;

		while (is_whitespace(line[end]))
			end++;
		start = end;
		while (!is_whitespace(line[end]))
			end++;
		if (line[end - 1] == ':')
			code->mark = ft_strcdup(line, ':');
		list = list->next;
	}
    code = (t_code*)malloc(sizeof(t_code));
}