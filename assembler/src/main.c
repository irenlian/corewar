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

void set_name(int fd, char *name)
{
    int i;
    char c;

    c = 0;
    i = 0;
    // write(fd, &name[0], 1);
    // write(fd, &name[1], 1);
    write(fd, name, i = ft_strlen(name));
    while(i < PROG_NAME_LENGTH + 4)
    {
        write(fd, &c, 1);
        i++;
    }
}   

int     main(int argc, char **argv)
{
    // t_bytes *cor;
    // t_str *champ;
    int fd;
    
    // cor = set_magic();
    fd = open("champ.cor", O_RDWR | O_CREAT | O_TRUNC, 777);
    set_magic(fd);
    // champ = read_file(argv[1]);
    set_name(fd, "Batman");
    // printf("%d", COREWAR_EXEC_MAGIC);
    return (0);
}