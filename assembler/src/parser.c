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
**	Save name of command to the structure and return start position of args
*/
int			save_name(t_code *code, t_list **list, int end)
{
	char	*line;
	int		start;

	while (((char*)(*list)->content)[0] == COMMENT_CHAR)
		(*list) = (*list)->next;
	line = (char*)(*list)->content;
	while (line[end] < 'a' || line[end] > 'z')
	{
		if (!line[end])
		{
			if (!(*list)->next)
				return (0);
			(*list) = (*list)->next;
			line = (char*)(*list)->content;
			end = 0;
		}
		else
			end++;
	}
	start = end;
	while (line[end]&& !is_whitespace(line[end]))
		end++;
	code->name = ft_strndup(line + start, end - start);
	while (is_whitespace(line[end]))
		end++;
	return (end);
}

/*
**	Parse args of command to struct t_code: min 1, max 3
*/
void		save_args(t_code *code, char *line)
{
	int		start;
	int		end;

	end = 0;
	while (line[end])
	{
		if (end > ft_strlen(line))
			return ;
		while (is_whitespace(line[end]))
			end++;
		start = end;
		while (line[end] && ft_isascii(line[end]) && line[end] != SEPARATOR_CHAR && !is_whitespace(line[end]))
		{
			if (line[end] == COMMENT_CHAR)
				return ;	
			end++;
		}
		if (!code->arg1)
			code->arg1 = ft_strndup(line + start, end - start);
		else if (!code->arg2 && line + start)
			code->arg2 = ft_strndup(line + start, end - start);
		else if (!code->arg3 && line + start)
			code->arg3 = ft_strndup(line + start, end - start);
		end++;
	}
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
	while (((char*)(*list)->content)[end - 1] == LABEL_CHAR)
	{
		line = (char*)(*list)->content;
		line[car[1] - car[0] - 1] = '\0';
		ft_lstpush(&code->mark, ft_lstnew(line, ft_strlen(line) + 1));
		end = 0;
		car[0] = end;
		if (!(*list)->next)
			return ;
		while (((char*)(*list)->next->content)[end] && !is_whitespace(((char*)(*list)->next->content)[end]))
			end++;
		if (((char*)(*list)->next->content)[end - 1] == LABEL_CHAR)
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
	
	line = (char*)(*list)->content;
	code = (t_code*)ft_memalloc(sizeof(t_code));
	code->id = ++i;
	if (line[car[1] - 1] == LABEL_CHAR)
		save_all_marks(code, list, car);
	car[0] = save_name(code, list, (code->mark) ? car[1] : car[0]);
	if (!code->name)
		return (0);
	save_args(code, (char*)(*list)->content + car[0]);
	return (code);
}

/*
**	Save asm code in t_code structure
*/
void			parse_code(t_champ *champ, t_list **code)
{
    int			car[2];
    t_list		*list;
	char		*line;
	t_code		*for_free;

	*code = NULL;
	list = champ->asm_code;
	while (list)
	{
		line = (char*)list->content;
		car[0] = 0;
		car[1] = 0;
		while (line[car[1]] && !is_whitespace(line[car[1]]))
			car[1]++;
		if (!ft_strnequ(line + car[0], NAME_CMD_STRING, car[1] - car[0]) &&
		!ft_strnequ(line + car[0], COMMENT_CMD_STRING, car[1] - car[0]) && line[0] &&
		line[car[0]] != COMMENT_CHAR)
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