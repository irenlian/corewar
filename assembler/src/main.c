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

// static t_command   *catalog;

int     get_arg_byte_size(t_command *com, char *arg)
{
    if (arg[0] == 'r')
        return (1);
    if (arg[0] == DIRECT_CHAR) 
       return (com->dir_size);
    return (2);
}

int     get_byte_size(t_code *code, t_command *catalog)
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
    return(count);
}

int    count_bytes(t_code *code, t_command *catalog)
{
    int count;

    count = 0;
    while (code)
    {
        code->byte_size = get_byte_size(code, catalog);
        count += code->byte_size;
        code = code->next;
    }
    return (count);
}

char *get_corname(char *file_name)
{
    int len;
    char    *result;

    len = ft_strlen(file_name);
    result = ft_memalloc(len + 3);
    ft_memcpy(result, file_name, len - 1);
    ft_strcat(result, "cor");
    return (result);
}

void    delete_before_relize(t_code *code)
{
    t_code  *tmp;
    t_code  *tmp2;

    tmp = (t_code*)malloc(sizeof(t_code));
    *tmp = (t_code){4, 0, NULL, "zjmp", "%:loop", NULL, NULL, NULL};
    tmp2 = (t_code*)malloc(sizeof(t_code));
    *tmp2 = (t_code){3, 0, NULL, "ld", "%0", "r2", NULL, tmp};
    tmp = (t_code*)malloc(sizeof(t_code));
    *tmp = (t_code){2, 0, "live", "live", "%0", NULL, NULL, tmp2};
    *code = (t_code){1, 0, "loop", "sti", "r1", "%:live", "%1", tmp};
}

int     main(int argc, char **argv)
{
    int fd;
    t_champ     *champ;
	t_code		*code;
    char        *champ_cor_name;
    t_command   *catalog;
    t_header   *header; // delete
    
    if (argc != 2 || !valid_champ_name(argv[1]))
        return (0);
    champ = (t_champ*)malloc(sizeof(t_champ));
    header = (t_header*)malloc(sizeof(t_header)); // delete
    champ->header = header; // delete
    champ->header->magic = COREWAR_EXEC_MAGIC; // delete
	code = (t_code*)malloc(sizeof(t_code));
    //TODO fill t_code here
    delete_before_relize(code); // delete
    read_code(champ, argv[1]);
    catalog = get_commad_catalog();
    champ->header->prog_size = count_bytes(code, catalog);
    champ_cor_name = get_corname(argv[1]);
    fd = open(champ_cor_name, O_RDWR | O_CREAT | O_TRUNC, 777);
    free(champ_cor_name);
    set_int(fd, champ->header->magic, 4);
    set_name(fd, champ->header->prog_name, PROG_NAME_LENGTH);
    set_int(fd, champ->header->prog_size, 4);
    set_name(fd, champ->header->comment, COMMENT_LENGTH);
    write_exec_code(fd, code, catalog);
    return (0);
}