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

int				save_name(t_code *code, t_list **list, int end)
{
	char		*line;
	int			start;

	while (is_comment(((char*)(*list)->content)[0]))
		(*list) = (*list)->next;
	line = (char *)(*list)->content;
	while (line[end] < 'a' || line[end] > 'z')
	{
		if (!line[end] || line[end] == COMMENT_CHAR || line[end] == ALT_COMMENT_CHAR)
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
	while (line[end] && !is_whitespace(line[end]))
	{
		
		end++;
	}
	code->name = ft_strndup(line + start, end - start);
	while (is_whitespace(line[end]))
		end++;
	return (end);
}

/*
**	Parse args of command to struct t_code: min 1, max 3
*/

void			save_args(t_code *code, char *line)
{
	int			start;
	int			end;

	end = 0;
	while (line[end])
	{
		if (end > ft_strlen(line))
			return ;
		while (is_whitespace(line[end]))
			end++;
		start = end;
		while (line[end] && line[end] != SEPARATOR_CHAR && SPACES)
		{
			if (is_comment(line[end]))
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
**	Check command after label in line, return 1 or 0
*/

int				check_commad_after(char *line, int i)
{
	while (line[++i])
	{
		if (line[i] == '#')
			return (0);
		if (line[i] > 'a' && line[i] < 'z')
			return (1);
	}
	return (0);
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
		line[end - car[0] - 1] = '\0';
		ft_lstpush(&code->mark, ft_lstnew(line, ft_strlen(line) + 1));
		end = 0;
		car[0] = end;
		if (!(*list)->next)
			return ;
		if (check_commad_after(line, car[1]))
			return ;
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
		return (0);
	return (code);
}

/*
**	Skip such lines as: "".name..."", "".comment..."
*/

void			skip_head(t_list **list)
{
	char	*line;
	int		i;

	line = (char*)(*list)->content;
	while (!ft_strnequ(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		(*list) = (*list)->next;
		line = (char*)(*list)->content;
	}
	i = 0;
	while (line[i] != '"')
		i++;
	while (line[++i])
	{
		if (line[i] == '"')
		{
			(*list) = (*list)->next;			
			return ;
		}
		else if (line[i + 1] == '\0')
		{
			(*list) = (*list)->next;
			line = (char*)(*list)->content;
			i = 0;
		}
	}
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

	list = champ->asm_code;
	while (list)
	{
		car[0] = 0;
		car[1] = 0;
		line = (char *)list->content;
		if (ft_strnequ(line, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
			skip_head(&list);
		line = (char *)list->content;
		while (line[car[1]] && !is_whitespace(line[car[1]]))
			car[1]++;
		if (!ft_strnequ(line + car[0], NAME_CMD_STRING, car[1] - car[0]) &&
			!ft_strnequ(line + car[0], COMMENT_CMD_STRING, car[1] - car[0])
			&& line[0] && !is_comment(line[car[0]]) && !ft_strchr(line, '"'))
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
