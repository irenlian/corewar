/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:54:00 by pdemian           #+#    #+#             */
/*   Updated: 2019/09/26 19:54:16 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			norm_error(t_champ *champ, char **line, int *start)
{
	if (champ->header->comment[0])
		show_error("Why so many comment? Don't do that!", -1);
	while ((*line)[++(*start)])
	{
		if ((*line)[(*start)] == '#')
			show_error("It is no comment of champion!", -1);
		if ((*line)[(*start)] == '"')
			break ;
	}
}

/*
**	Skip such lines as: "".name..."", "".comment..."
*/

void			skip_head(t_list **list)
{
	char	*line;
	int		i;

	while (!ft_strnequ(LINE, COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
	{
		(*list) = (*list)->next;
		line = (char*)(*list)->content;
	}
	i = 0;
	while (line[i] != '"')
		i++;
	while (line[++i] || line[i - 1] || line)
	{
		if (line[i] == '"' || line[0] == '"')
		{
			(*list) = (*list)->next;
			return ;
		}
		else if (line[i + 1] == '\0' || line[i] == '\0')
		{
			(*list) = (*list)->next;
			line = (char*)(*list)->content;
			i = 0;
		}
	}
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
		if (end > (int)ft_strlen(line))
			return ;
		if (SPACES || line[end] == SEPARATOR_CHAR)
			while (line[end] && (SPACES || line[end] == SEPARATOR_CHAR))
				end++;
		if (is_comment(line[end]))
			return ;
		start = end;
		while (line[end] && line[end] != SEPARATOR_CHAR &&
			!SPACES && !is_comment(line[end]))
			end++;
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
