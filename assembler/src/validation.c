#include "corewar.h"

int			show_error(const char *error)
{
    // system("leaks asm");
	ft_printf("%t%s%t\n", B_RED, error, EOC);
	exit(0);
}

int valid_magic(char *magic)
{
    if (magic[0] == '0' && (magic[1] == 'x' || magic[1] == 'X'))
        return (1);
    return (0);
}

int valid_champ_name(char *name)
{
    int len;

    len = ft_strlen(name);
    if (len < 2 || name[len - 1] != 's' || name[len - 2] != '.')
        return (0);
    return (1);
}

int valid_head(t_list *champ)
{
    int i;
    int is_name;
    int is_comment;

    is_name = 0;
    is_comment = 0;
    i = 0;
    while (champ)
    {
        if (ft_strstr(champ->content, NAME_CMD_STRING) && !is_name)
            is_name = 1;
        else if (ft_strstr(champ->content, COMMENT_CMD_STRING) && !is_comment)
            is_comment = 1;
        else if (is_name && is_comment)
            return (1);
        else
        {
            ft_printf("%s %i\n", "Syntax error at line:", i);
            return (0);
        }
        champ = champ->next;
        i++;
    }
    return (0);
}


int valid_command_line(char *line)
{
    int i;

    i = -1;
    while (line[++i] != '\0')
    {
        if (line[i] == COMMENT_CHAR)
            break;
        if (line[i] == ' ' || line[i] == '\t')
            continue;
    }
    return (1);
}

int valid_champ_file(t_list *champ)
{
    t_list *tmp;
    int i;

    if (!valid_head(champ))
        return (0);
    tmp = champ->next->next;
    i = 0;
    while (tmp)
    {
        if (!valid_command_line(tmp->content))
        {
            ft_printf("%s %i\n", "Syntax error at line:", i);
            return (0);
        }
        tmp = tmp->next;
        i++;
    }
    return (1);
}