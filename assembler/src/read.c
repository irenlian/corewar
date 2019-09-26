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
**	Read .cor file for disassembler, if read return (2), else (0)
*/

int				read_cor(t_champ *champ, int fd)
{
	show_error("It's .cor file", -1);
	return (2);
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
