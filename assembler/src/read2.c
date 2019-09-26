/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:59:33 by pdemian           #+#    #+#             */
/*   Updated: 2019/09/26 19:59:47 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			push_asm_code(t_champ *champ, char *trim_line)
{
	if (trim_line)
		ft_lstpush(&champ->asm_code, ft_lstnew(trim_line,
			ft_strlen(trim_line) + 1));
	ft_strdel(&trim_line);
}

/*
**	Norminette)
*/

void			read_next_lines(t_champ *champ, char **line, int fd, int *i)
{
	char	*trim_line;

	champ->header->prog_name[++(*i)] = '\n';
	ft_strdel(line);
	get_next_line(fd, line);
	trim_line = ft_strtrim(*line);
	if (ft_strstr((*line), COMMENT_CMD_STRING))
		show_error("Your name is invalid!", -1);
	if ((*line))
		push_asm_code(champ, trim_line);
}

/*
**	Search for name of champion
*/

void			get_name(t_champ *champ, char **line, int fd)
{
	int		i;
	int		star;

	star = -1;
	if (champ->header->prog_name[0])
		show_error("Why so many names? Don't do that!", -1);
	while ((*line)[++star])
	{
		if ((*line)[star] == COMMENT_CHAR || (*line)[star] == ALT_COMMENT_CHAR)
			show_error("It is no name of champion!", -1);
		if ((*line)[star] == '"')
			break ;
	}
	i = -1;
	while ((*line)[++star] != '"')
	{
		champ->header->prog_name[++i] = (*line)[star];
		if (i > PROG_NAME_LENGTH)
			show_error("Too long prog_name", -1);
		if ((*line)[star + 1] == '\0')
		{
			read_next_lines(champ, line, fd, &i);
			star = -1;
		}
	}
}

/*
**	Search comment of champion
*/

void			get_comment(t_champ *champ, char **line, int fd)
{
	int		i;
	int		start;
	char	*trim_line;

	start = -1;
	norm_error(champ, line, &start);
	i = -1;
	while ((*line)[++start] != '"')
	{
		if ((*line)[start])
			champ->header->comment[++i] = (*line)[start];
		if (i >= COMMENT_LENGTH)
			show_error("Too long comment", -1);
		if ((*line)[start + 1] == '\0')
		{
			champ->header->comment[++i] = '\n';
			ft_strdel(line);
			get_next_line(fd, line);
			trim_line = ft_strtrim(*line);
			push_asm_code(champ, trim_line);
			if (!(*line))
				show_error("Your comment is invalid!", -1);
			start = -1;
		}
	}
}

/*
**	Read asm code, if read return (1), else (0)
*/

int				read_asm(t_champ *champ, int fd)
{
	char	*line;
	char	*trim_line;

	champ->asm_code = NULL;
	if (read(fd, NULL, 0) < 0)
		show_error("Something wrong with file", -1);
	while (get_next_line(fd, &line) > 0)
	{
		trim_line = ft_strtrim(line);
		if (ft_strnequ(trim_line, NAME_CMD_STRING, 5))
		{
			push_asm_code(champ, trim_line);
			get_name(champ, &line, fd);
		}
		else if (ft_strnequ(trim_line, COMMENT_CMD_STRING, 8))
		{
			push_asm_code(champ, trim_line);
			get_comment(champ, &line, fd);
		}
		else if (trim_line)
			push_asm_code(champ, trim_line);
		ft_strdel(&line);
	}
	return (1);
}
