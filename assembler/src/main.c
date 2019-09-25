/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:11:56 by pdemian           #+#    #+#             */
/*   Updated: 2019/09/11 19:12:33 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			check_code(t_list *list)
{
	t_code *code;
	int i;

	i = 0;
	while (list)
	{
		code = (t_code *)list->content;
		while (code->mark)
		{
			printf("%s:\n", (char *)code->mark->content);
			code->mark = code->mark->next;
		}
		printf("%d)", code->id);
		printf("		%s", code->name);
		printf("		%s", code->arg1);
		(code->arg2) ? printf(", %s", code->arg2) : printf("");
		(code->arg3) ? printf(", %s", code->arg3) : printf("");
		printf("\n");
		list = list->next;
	}
}

int				get_arg_byte_size(t_command *com, char *arg)
{
	if (arg[0] == 'r')
		return (1);
	if (arg[0] == DIRECT_CHAR)
		return (com->dir_size);
	return (2);
}

int				get_byte_size(t_code *code, t_command *catalog)
{
	int count;
	t_command *com;

	com = get_com_byname(catalog, code->name);
	if (!com)
		return (0);
	count = 1;
	if (code->arg1)
		count += get_arg_byte_size(com, code->arg1);
	if (code->arg2)
		count += get_arg_byte_size(com, code->arg2);
	if (code->arg3)
		count += get_arg_byte_size(com, code->arg3);
	if (com->codage_octal)
		count++;
	return (count);
}

int				count_bytes(t_list *code_list, t_command *catalog)
{
	int count;
	t_code *code;

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

char			*get_corname(char *file_name)
{
	int		len;
	char	*result;

	len = ft_strlen(file_name);
	result = ft_memalloc(len + 3);
	ft_memcpy(result, file_name, len - 1);
	ft_strcat(result, "cor");
	return (result);
}

int     main(int argc, char **argv)
{
	int			fd;
	t_champ		*champ;
	t_list		*code;
    char        *champ_cor_name;
    t_command   *catalog;
    
    if (argc != 2 || !valid_champ_name(argv[1]))
        return (0);
    champ = (t_champ*)ft_memalloc(sizeof(t_champ));
    champ->header = (t_header*)ft_memalloc(sizeof(t_header));
    read_code(champ, argv[1]);
    catalog = get_commad_catalog();
    valid_champ_file(champ->asm_code, catalog);
	parse_code(champ, &code);
    // valid_existing_labels(code);
    champ->header->prog_size = count_bytes(code, catalog);
    champ_cor_name = get_corname(argv[1]);
    fd = open(champ_cor_name, O_RDWR | O_CREAT | O_TRUNC, 777);
    free(champ_cor_name);
    set_int(fd, champ->header->magic, 4);
    set_name(fd, champ->header->prog_name, PROG_NAME_LENGTH);
    set_int(fd, champ->header->prog_size, 4);
    set_name(fd, champ->header->comment, COMMENT_LENGTH);
    write_exec_code(fd, code, catalog);
	ft_printf("%tOutput to .cor file%t\n", B_WHITE, EOC);
    // system("leaks asm");
    return (0);
}