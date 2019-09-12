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

// void		print_file(t_champ *champ)
// {
// 	t_list 	*list;

// 	list = champ->asm_code;
// 	while (list)
// 	{
// 		printf("%s\n", list->content);
// 		list = list->next;
// 	}
// }

// t_str   *read_file(char *path)
// {
//     t_str *str;
//     t_str *tmp;
//     char *line;
//     int fd;

//     str = NULL;
//     line = NULL;
//     fd = open(path, O_RDONLY);
//     while (get_next_line(fd, &line) > 0)
//     {
//         tmp = create_tstr(line);
//         if (!str)
//             str = tmp;
//         tmp = tmp->next;
//     }
//     return (str);
// }

void set_magic(int fd)
{
    char c = 0;
    int magic = COREWAR_EXEC_MAGIC;
	
    c = magic >> (3 * 8);
    write(fd, &c, 1);
    c = magic >> (2 * 8);    
    write(fd, &c, 1);
    c = magic >> (8);    
    write(fd, &c, 1);
    c = magic;
    write(fd, &c, 1);
}

void set_name(int fd, char *name, int max_length)
{
    int i;
    char c;

    c = 0;
    i = 0;
    write(fd, name, ((i = ft_strlen(name)) < max_length) ? i : max_length);
    while(i < max_length)
    {
        write(fd, &c, 1);
        i++;
    }
    i = 0;
    write(fd, &c, 1);
    write(fd, &c, 1);
    write(fd, &c, 1);
    write(fd, &c, 1);
}

int     get_dir_size(char *code)
{
    if(
        ft_strnequ(code, "zjmp", ft_strchr(code, ' ') - code - 2) ||
        ft_strnequ(code, "ldi", ft_strchr(code, ' ') - code - 2) ||
        ft_strnequ(code, "sti", ft_strchr(code, ' ') - code - 2) ||
        ft_strnequ(code, "fork", ft_strchr(code, ' ') - code - 2) ||
        ft_strnequ(code, "lldi", ft_strchr(code, ' ') - code - 2) ||
        ft_strnequ(code, "lfork", ft_strchr(code, ' ') - code - 2))
        return (2);
    else
        return (4);
}

int     get_arg_byte_size(char *code, char *arg)
{
    int i;

    i = 0;
    while(arg[i] != '\0' && arg[i] == ' ')
        i++;
    if (arg[i] == '\0')
        return (0);
    if (arg[i] == 'r')
        return (1);
    if (arg[i] == DIRECT_CHAR)
        return (get_dir_size(code));
    else
        return (2);
    
}

int     get_byte_size(char *code)
{
    int i;
    int count;

    i = -1;
    count = 0;
    while(code[++i] != '\0')
    {
        if (code[i] == ' ')
            continue;
        if (code[i] == SEPARATOR_CHAR)
            count += get_arg_byte_size(code, &code[i + 1]);
    }
    return(count);
}

void    count_bytes(t_list *str)
{
    while (str)
    {
        get_byte_size(str->content);
        str = str->next;
    }
}


int     main(int argc, char **argv)
{
    t_champ     *champ;
    int fd;
    
    champ = (t_champ*)malloc(sizeof(t_champ));

    // cor = set_magic();
	
    read_code(champ, argv[1]);

    fd = open("champ.cor", O_RDWR | O_CREAT | O_TRUNC, 777);
    set_magic(fd);
    // champ = read_file(argv[1]);
    set_name(fd, "This city needs me", COMMENT_LENGTH);
    int result = get_byte_size("sti r1, %:live, %1");
    // printf("%d", COREWAR_EXEC_MAGIC);
    // system("leaks asm");
    return (0);
}