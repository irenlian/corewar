/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:59:01 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:59:03 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Getting name of champion
*/

void			get_name(t_champ *champ, char **line, int fd)
{
	int		i;
	int		start;

	start = -1;
	if (champ->header->prog_name[0])
		show_error("Why so many names? Don't do that!", -1);
	while ((*line)[++start])
	{
		if ((*line)[start] == COMMENT_CHAR || (*line)[start] == ALT_COMMENT_CHAR)
			show_error("It is no name of champion!", -1);
		if ((*line)[start] == '"')
			break ;
	}
	i = -1;
	while ((*line)[++start] != '"')
	{
		champ->header->prog_name[++i] = (*line)[start];
		if (i > PROG_NAME_LENGTH)
			show_error("Too long prog_name", -1);
		if ((*line)[start + 1] == '\0')
		{
			champ->header->prog_name[++i] = '\n';
			ft_strdel(line);
			get_next_line(fd, line);
			if (ft_strstr((*line), COMMENT_CMD_STRING))
				show_error("Your name is invalid!", -1);
			start = -1;
		}
	}
}

void			get_comment(t_champ *champ, char **line, int fd)
{
	int		i;
	int		start;
	char	*trim_line;

	if (champ->header->comment[0])
		show_error("Why so many comment? Don't do that!", -1);
	start = -1;
	while ((*line)[++start])
	{
		if ((*line)[start] == '#')
			show_error("It is no comment of champion!", -1);
		if ((*line)[start] == '"')
			break ;
	}
	i = -1;
	while ((*line)[++start] != '"')
	{
		if ((*line)[start])
			champ->header->comment[++i] = (*line)[start];
		if (i >= COMMENT_LENGTH)
			show_error("Too long comment", -1);
		if ((*line)[start + 1] == '\0')
		{
			if (champ->header->comment[0] == '\0')
			{
				i = -1;
				champ->header->comment[++i] = '\n';
			}
			else
				champ->header->comment[++i] = '\n';
			ft_strdel(line);
			get_next_line(fd, line);
			trim_line = ft_strtrim(*line);
			if (!(*line))
				show_error("Your comment is invalid!", -1);
			if ((*line))
				ft_lstpush(&champ->asm_code, ft_lstnew(trim_line,
					ft_strlen(trim_line) + 1));
			start = -1;
		}
	}
}

/*
**	Read .cor file for disassembler, if read return (2), else (0)
*/

int				read_cor(t_champ *champ, int fd)
{
	show_error("It's .cor file", -1);
	return (2);
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
			if (trim_line)
			ft_lstpush(&champ->asm_code, ft_lstnew(trim_line,
				ft_strlen(trim_line) + 1));
			get_name(champ, &line, fd);
		}
		else if (ft_strnequ(trim_line, COMMENT_CMD_STRING, 8))
		{
			if (trim_line)
			ft_lstpush(&champ->asm_code, ft_lstnew(trim_line,
				ft_strlen(trim_line) + 1));
			get_comment(champ, &line, fd);
		}
		else if (trim_line)
			ft_lstpush(&champ->asm_code, ft_lstnew(trim_line,
				ft_strlen(trim_line) + 1));
		ft_strdel(&line);
		ft_strdel(&trim_line);
	}
	champ->header->magic = COREWAR_EXEC_MAGIC;
	return (1);
}

/*
**  Read file .s (return 1) or .cor (return 2)
*/

int				read_code(t_champ *champ, char *f_name)
{
	int		i;
	int		fd;

	fd = open(f_name, O_RDONLY);
	i = -1;
	f_name = ft_strrchr(f_name, '.');
	if (ft_strequ(f_name + 1, "s"))
		return (read_asm(champ, fd));
	else if (ft_strequ(f_name + 1, "cor"))
		return (read_cor(champ, fd));
	else
		show_error("Wrong file format", -1);
	return (0);
}
