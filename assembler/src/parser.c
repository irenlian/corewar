/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:58:53 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:58:55 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int				skip_name(char *line, int end)
{
	while (line[end] && !is_whitespace(line[end]) && line[end] != LABEL_CHAR
	&& line[end] != DIRECT_CHAR && line[end] != '-' && !ft_isdigit(line[end]))
		end++;
	return (end);
}

/*
**	Save name of command to the structure and return start position of args
*/

int				save_name(t_code *code, t_list **list, int end)
{
	char		*line;
	int			start;

	while (is_comment(((char*)(*list)->content)[0]))
		(*list) = (*list)->next;
	line = (char *)(*list)->content;
	while (line[end] < 'a' || line[end] > 'z')
	{
		if (!line[end] || is_comment(line[end]))
		{
			if (!(*list)->next)
				return (0);
			(*list) = (*list)->next;
			line = (char *)(*list)->content;
			end = 0;
		}
		else
			end++;
	}
	start = end;
	end = skip_name(line, end);
	code->name = ft_strndup(line + start, end - start);
	while (is_whitespace(line[end]) && line[end])
		end++;
	return (end);
}

/*
**	Save all marks if there are more than 1 to the list
*/

void			save_all_marks(t_code *code, t_list **list, int *car)
{
	t_list		*marks;
	char		*line;
	int			end;

	end = car[1];
	marks = NULL;
	while (((char *)(*list)->content)[end - 1] == LABEL_CHAR)
	{
		line = (char *)(*list)->content;
		line[end - 1] = '\0';
		ft_lstpush(&code->mark, ft_lstnew(line, ft_strlen(line) + 1));
		car[1] = end;
		end = 0;
		if (!(*list)->next)
			return ;
		if (check_commad_after(line, car[1]))
			return ;
		while (((char *)(*list)->next->content)[0] == '\0')
			*list = (*list)->next;
		while (((char *)(*list)->next->content)[end] &&
			!is_whitespace(((char *)(*list)->next->content)[end]))
			end++;
		if (((char *)(*list)->next->content)[end - 1] == LABEL_CHAR)
			*list = (*list)->next;
	}
}

/*
**	Create t_code struct for adding to the list
*/

t_code			*make_code(t_list **list, int *car)
{
	static int		i = 0;
	t_code			*code;
	char			*line;

	line = (char *)(*list)->content;
	code = (t_code *)ft_memalloc(sizeof(t_code));
	code->id = ++i;
	if (line[car[1] - 1] == LABEL_CHAR)
		save_all_marks(code, list, car);
	car[0] = save_name(code, list, (code->mark) ? car[1] : car[0]);
	save_args(code, (char *)(*list)->content + car[0]);
	if (!code->name || !code->arg1)
	{
		if (!code->name && code->mark)
			return (code);
		return (0);
	}
	return (code);
}

/*
**	Save asm code in t_code structure
*/

void			parse_code(t_champ *champ, t_list **code)
{
	int			car[2];
	t_list		*list;
	t_code		*for_free;

	list = champ->asm_code;
	while (list)
	{
		car[0] = 0;
		car[1] = 0;
		if (ft_strnequ(LINP, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			skip_head(&list);
		while (LINP[car[1]] && !is_whitespace(LINP[car[1]]) && LINP[car[1] - 1]
			!= LABEL_CHAR && LINP[car[1]] != DIRECT_CHAR)
			car[1]++;
		if (NORM1 && NORM2 && NORM3)
		{
			for_free = make_code(&list, car);
			if (for_free)
				ft_lstadd(code, ft_lstnew(for_free, sizeof(t_code)));
			free(for_free);
		}
		list = list->next;
	}
	ft_lstrev(code);
}
