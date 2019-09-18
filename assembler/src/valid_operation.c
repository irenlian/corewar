#include "corewar.h"

void    valid_dir_arg(char *dir)
{
    int i;
    int status;

    i = 0;
    status = 0;
    if(dir[0] == '\0' || dir[0] != DIRECT_CHAR || dir[1] == '\0')
        show_error("not valid arg");
    while (dir[++i] != '\0')
    {
        if (status == 0 && dir[i] == DIRECT_CHAR)
            status = 1;
        else if (status == 1 && dir[i] == LABEL_CHAR)
            status = 2;
        else if ((status == 2 || status == 4) && ft_strchr(LABEL_CHARS, dir[i]))
            status = 4;
        else if ((status == 1 && ft_strchr("-123456789", dir[i])) || (status == 3 && ft_strchr("0123456789", dir[i])))
            status = 3;
       else if ((status == 3 || status == 4) && dir[i] == SEPARATOR_CHAR)
            break ;
        else if (status == 0 && (dir[i] == ' ' || dir[i] == '\t'))
            continue ;
        else
            break;
    }
    while (dir[i] != '\0' && (dir[i] == ' ' || dir[i] == '\t'))
        i++;
    if ((dir[i] != SEPARATOR_CHAR && dir[i] != '\0') || (status != 3 && status != 4))
        show_error("not valid arg");  
}
void    valid_type_live(char *args)
{
    valid_dir_arg(args);
}

void    valid_type_ld(char *args)
{

}

void    valid_type_st(char *args)
{

}

void    valid_type_add(char *args)
{

}

void    valid_type_and(char *args)
{

}

void    valid_type_ldi(char *args)
{

}

void    valid_type_sti(char *args)
{

}

void    valid_type_aff(char *args)
{

}

void    valid_by_type_operation(char *name, char *args)
{
    if (ft_strequ(name, "live") || ft_strequ(name, "zjmp") || ft_strequ(name, "fork") || ft_strequ(name, "lfork"))
        valid_type_live(args);
    else if (ft_strequ(name, "ld") || ft_strequ(name, "lld"))
        valid_type_ld(args);
    else if (ft_strequ(name, "st"))
        valid_type_st(args);
    else if (ft_strequ(name, "add") || ft_strequ(name, "sub"))
        valid_type_add(args);
    else if (ft_strequ(name, "and") || ft_strequ(name, "or") || ft_strequ(name, "xor"))
        valid_type_and(args);
    else if (ft_strequ(name, "ldi") || ft_strequ(name, "lldi"))
        valid_type_ldi(args);
    else if (ft_strequ(name, "sti"))
        valid_type_sti(args);
    else if (ft_strequ(name, "aff"))
        valid_type_aff(args);
    else
    {
        ft_printf("%s\n", "Syntax error at token [TOKEN] INSTRUCTION \"___\"");
        exit(0);
    }
}

void valid_operation(char *line)
{
    int i;
    int j;
    char operation_name[6];

    i = -1;
    j = 0;
    while (line[++i] != '\0')
    {
        if (line[i] == COMMENT_CHAR)
            break;
        if ((line[i] == ' ' || line[i] == '\t') && j == 0)
            continue;
        else if (line[i] == ' ' || line[i] == '\t')
            break;
        if (j == 6)
            show_error("not valid operation");
        operation_name[j++] = line[i];
    }
    valid_by_type_operation(operation_name, &line[i]);
}