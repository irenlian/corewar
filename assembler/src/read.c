/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:04:56 by pdemian           #+#    #+#             */
/*   Updated: 2019/09/12 18:05:00 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Getting name of champion
*/

void			get_name(t_champ *champ, char *line)
{
	int		i;
	int		s;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '"')
		{
			s = i;
			i++;
			while (line[i] != '"')
				i++;
			break ;
		}
	}
	// champ->header->prog_name = ft_strnew(i - s - 1);
	i = -1;
	while (line[++s] != '"')
		champ->header->prog_name[++i] = line[s];
}

/*
**	Read .cor file for disassembler, if read return (2), else (0)
*/

int				read_cor(t_champ *champ, int fd)
{
	show_error("It's .cor file");
	return (2);
}

/*
**	Read asm code, if read return (1), else (0)
*/

int				read_asm(t_champ *champ, int fd)
{
	char	*line;

	champ->asm_code = NULL;
	if (read(fd, NULL, 0) < 0)
		show_error("Something wrong with file");
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, ".name"))
			get_name(champ, line);
		ft_lstpush(&champ->asm_code,
			ft_lstnew(line, sizeof(char) * ft_strlen(line) + 1));
		ft_strdel(&line);
	}
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
		show_error("Wrong file format");
	return (0);
}
