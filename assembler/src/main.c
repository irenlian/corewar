/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:58:22 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:58:24 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			get_byte_size(t_code *code, t_command *catalog)
{
	int			count;
	t_command	*com;

	com = get_com_byname(catalog, code->name);
	if (!code->name || !com)
		return (0);
	count = 1;
	if (code->arg1)
		count += get_size_arg(code->arg1, com);
	if (code->arg2)
		count += get_size_arg(code->arg2, com);
	if (code->arg3)
		count += get_size_arg(code->arg3, com);
	if (com->codage_octal)
		count++;
	return (count);
}

int			count_bytes(t_list *code_list, t_command *catalog)
{
	int		count;
	t_code	*code;

	count = 0;
	while (code_list)
	{
		code = (t_code *)(code_list->content);
		code->byte_size = get_byte_size(code, catalog);
		count += code->byte_size;
		code_list = code_list->next;
	}
	return (count);
}

char		*get_corname(char *file_name)
{
	int		len;
	char	*result;

	len = ft_strlen(file_name);
	result = ft_memalloc(len + 3);
	ft_memcpy(result, file_name, len - 1);
	ft_strcat(result, "cor");
	return (result);
}

void		set_magic(t_champ *champ, int fd)
{
	set_int(fd, champ->header->magic, 4);
	set_name(fd, champ->header->prog_name, PROG_NAME_LENGTH);
	set_int(fd, champ->header->prog_size, 4);
	set_name(fd, champ->header->comment, COMMENT_LENGTH);
}

int			main(int argc, char **argv)
{
	int			fd;
	t_champ		*champ;
	t_list		*code;
	char		*champ_cor_name;
	t_command	*catalog;

	if (argc != 2 || !valid_champ_name(argv[1]))
		show_error("Incorrect number of arguments", -1);
	champ = (t_champ *)ft_memalloc(sizeof(t_champ));
	champ->header = (t_header *)ft_memalloc(sizeof(t_header));
	read_code(champ, argv[1]);
	catalog = get_commad_catalog();
	valid_champ_file(champ->asm_code);
	parse_code(champ, &code);
	valid_existing_labels(code);
	champ->header->prog_size = count_bytes(code, catalog);
	champ->header->magic = COREWAR_EXEC_MAGIC;
	champ_cor_name = get_corname(argv[1]);
	fd = open(champ_cor_name, O_RDWR | O_CREAT | O_TRUNC, 777);
	free(champ_cor_name);
	set_magic(champ, fd);
	write_exec_code(fd, code, catalog);
	ft_printf("%tOutput to .cor file%t\n", B_WHITE, EOC);
	return (0);
}
