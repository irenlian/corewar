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

static t_command   *catalog;

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

// char    *get_code_name(char *code)
// {
//      char name[6];
//      int i;

//      i = 0;
//      while (i < 6 && code[i] != '\0')
//      {
//          if (code[i] == ' ')
//          {
//             name[i] = '\0';
//             break ;
//          }
//          name[i] = code[i];
//          i++;
//      }
//      return (&(name[0]));
// }

// int     get_arg_byte_size(char *code, char *arg)
// {
//     int i;
//     t_command *com;

//     i = 0;
//     while(arg[i] != '\0' && arg[i] == ' ')
//         i++;
//     if (arg[i] == '\0')
//         return (0);
//     if (arg[i] == 'r')
//         return (1);
//     if (arg[i] == DIRECT_CHAR)
//     {
//        com = get_com_byname(catalog, get_code_name(code));
//        return (com->dir_size);
//     }
//     else
//         return (2);
    
// }

// int     get_byte_size(char *code)
// {
//     int i;
//     int count;

//     i = -1;
//     count = 0;
//     while(code[++i] != '\0')
//     {
//         if (code[i] == ' ')
//             break;
//     }
//     while(code[i] != '\0')
//     {
//         if (ft_strchr("r0123456789", code[i]) || code[i] == DIRECT_CHAR || code[i] == LABEL_CHAR)
//         {
//             count += get_arg_byte_size(code, &code[i]);
//             while (code[i] != '\0' && code[i] != SEPARATOR_CHAR)
//                 i++;
//         }
//         if (code[i] == '\0')
//             break ;
//         i++;
//     }
//     return(count);
// }

// int    count_bytes(t_list *str)
// {
//     int count;

//     count = 0;
//     while (str)
//     {
//         if (((char*)str->content)[ft_strlen(str->content) - 1] == ':')
//             count += get_byte_size(str->content);
//         str = str->next;
//     }
//     return (count);
// }


int     main(int argc, char **argv)
{
    int fd;
    t_champ     *champ;
    
    champ = (t_champ*)malloc(sizeof(t_champ));
    read_code(champ, argv[1]);
    catalog = get_commad_catalog();
    fd = open("champ.cor", O_RDWR | O_CREAT | O_TRUNC, 777);
    set_magic(fd);
    set_name(fd, "This city needs me", COMMENT_LENGTH);
    // int result = get_byte_size("sti r1, %:live, %1");
    return (0);
}