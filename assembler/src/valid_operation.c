#include "corewar.h"

int    valid_dir_arg(char *dir)
{
    int i;
    int status;

    i = -1;
    status = 0;
    // if(dir[0] == '\0' || dir[0] != DIRECT_CHAR || dir[1] == '\0')
    //     show_error("not valid arg");
    while (dir[++i] != '\0')
    {
        if (status == 0 && dir[i] == DIRECT_CHAR)
            status = 1;
        else if (status == 1 && dir[i] == LABEL_CHAR)
            status = 2;
        else if ((status == 2 || status == 4) && ft_strchr(LABEL_CHARS, dir[i]))
            status = 4;
        else if ((status == 1 && ft_strchr("-0123456789", dir[i])) || (status == 3 && ft_strchr("0123456789", dir[i])))
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
        return (0);
    return (1);
}

int    valid_ind_arg(char *arg)
{
    int i;
    int status;

    i = -1;
    status = 0;
    while (arg[++i] != '\0')
    {
        if (status == 0 && (arg[i] == ' ' || arg[i] == '\t'))
            continue ;
        else if (status == 0 && arg[i] == LABEL_CHAR)
            status = 1;
        else if ((status == 1 || status == 3) && ft_strchr(LABEL_CHARS, arg[i]))
            status = 3;
        else if ((status == 0 && ft_strchr("-0123456789", arg[i])) || (status == 2 && ft_strchr("0123456789", arg[i])))
            status = 2;
       else if ((status == 2 || status == 3) && arg[i] == SEPARATOR_CHAR)
            break ;
        else
            break;
    }
    while (arg[i] != '\0' && (arg[i] == ' ' || arg[i] == '\t'))
        i++;
    if ((arg[i] != SEPARATOR_CHAR && arg[i] != '\0') || (status != 2 && status != 3))
        return (0);
    return (1);
}

int    valid_reg_arg(char *arg)
{
    int i;
    int status;

    i = -1;
    status = 0;
    while (arg[++i] != '\0')
    {
        if (arg[i] == ' ' || arg[i] == '\t')
            continue ;
        else if (status == 0 && arg[i] == 'r')
            status = 1;
        else if ((status == 1 || status == 2) && ft_strchr("0123456789", arg[i]))
            status = 2;
        else
            break;
    }
    while (arg[i] != '\0' && (arg[i] == ' ' || arg[i] == '\t'))
        i++;
    if ((arg[i] != SEPARATOR_CHAR && arg[i] != '\0') || status != 2)
        return (0);
    return (1);
}

void    valid_type_live(char *args)
{
    if (!valid_dir_arg(args))
        show_error("Arg error");
    if (ft_strchr(args, SEPARATOR_CHAR))
        show_error("Arg error");
}

void    valid_type_ld(char *args)
{
    int i;

    i = -1;
    if (!valid_dir_arg(args) && !valid_ind_arg(args))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]))
        show_error("Arg error");
    if (ft_strchr(&args[i + 1], SEPARATOR_CHAR))
        show_error("Arg error");
}

void    valid_type_st(char *args)
{
    int i;

    i = -1;
    if (!valid_reg_arg(args))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]) && !valid_ind_arg(&args[i + 1]))
        show_error("Arg error");
}

void    valid_type_add(char *args)
{
    int i;

    i = -1;
    if (!valid_reg_arg(args))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]))
        show_error("Arg error");
}

void    valid_type_and(char *args)
{
    int i;

    i = -1;
    if (!valid_reg_arg(args) && !valid_ind_arg(args) && valid_dir_arg(args))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]) && !valid_ind_arg(&args[i + 1]) && !valid_dir_arg(&args[i + 1]))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]))
        show_error("Arg error");
    if (ft_strchr(&args[i + 1], SEPARATOR_CHAR))
        show_error("Arg error");
}

void    valid_type_ldi(char *args)
{
    int i;

    i = -1;
    if (!valid_reg_arg(args) && !valid_ind_arg(args) && valid_dir_arg(args))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]) && !valid_dir_arg(&args[i + 1]))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]))
        show_error("Arg error");
    if (ft_strchr(&args[i + 1], SEPARATOR_CHAR))
        show_error("Arg error");
}

void    valid_type_sti(char *args)
{
    int i;

    i = -1;
    if (!valid_reg_arg(args))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]) && !valid_ind_arg(&args[i + 1]) && !valid_dir_arg(&args[i + 1]))
        show_error("Arg error");
    while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR);
    if (!valid_reg_arg(&args[i + 1]) && !valid_dir_arg(&args[i + 1]))
        show_error("Arg error");
    if (ft_strchr(&args[i + 1], SEPARATOR_CHAR))
        show_error("Arg error");
}

void    valid_type_aff(char *args)
{
    if (!valid_reg_arg(args))
        show_error("Arg error");
    if (ft_strchr(args, SEPARATOR_CHAR))
        show_error("Arg error");
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
    ft_memset(operation_name, '\0', 6);
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