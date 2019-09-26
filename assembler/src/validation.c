#include "corewar.h"

int			show_error(const char *error, int err_index)
{
    // system("leaks asm");
    if (err_index < 0)
	    ft_printf("%tERROR: %t%s%t\n", B_RED, B_WHITE, error, EOC);
    else
        ft_printf("%t%s%d%t\n", B_RED, error, err_index + 1, EOC);
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

int count_char(char *line, char c)
{
    int i;
    int count;

    i = -1;
    count = 0;
    while (line[++i] != '\0')
    {
        if (line[i] == c)
            count++;
    }
    return (count);
}

int	get_status_head(char *line)
{
	int status;
	int count_ch;

	status = 1;
	count_ch = count_char(line, '"');
	if (count_ch == 2)
		status = 3;
	else if (count_ch == 1)
		status = 2;
	return (status);
}

int valid_head(t_list *champ)
{
    int i;
	int head_status[2];

    i = 0;
	head_status[0] = 0;
	head_status[1] = 1;
    while (champ && ++i)
    {
		if (head_status[0] == 2 && ft_strchr(champ->content, '"'))
            head_status[0] = 3;
        else if (head_status[1] == 2 && ft_strchr(champ->content, '"'))
            head_status[1] = 3;
		else if (!is_comment(((char *)(champ->content))[0]))
		{
			if (ft_strstr(champ->content, NAME_CMD_STRING))
				head_status[0] = get_status_head(champ->content);
			else if (ft_strstr(champ->content, COMMENT_CMD_STRING))
				head_status[1] = get_status_head(champ->content);
			else if (((char *)(champ->content))[0] != '\0' && !head_status[0] && !head_status[1])
				show_error("Not valid head at line: ", i);
		}
        if (head_status[0] == 3 && head_status[1] == 3)
            return (i);
        champ = champ->next;
    }
    return (show_error("Not valid head", -1));
}

void    valid_label(char *line, int pos_label_char, int line_index)
{
    int status;

    status = 0;
    while (--pos_label_char >= 0)
    {
        if ((status == 0 || status == 1) && ft_strchr(LABEL_CHARS, line[pos_label_char]))
            status = 1;
        else if ((status == 1 || status == 2) && ft_strchr(" \t", line[pos_label_char]))
            status = 2;
        else
            show_error("Label error in line: ", line_index);
    }
}

void    valid_command_line(char *line, int line_index, t_command *catalog)
{
    int i;
    int j;
    char *pos;

    i = -1;
    j = -1;
    while (line[++j] != '\0')
    {
        if(is_comment(line[j]))
        // if ((ft_strchr(line, COMMENT_CHAR) && ft_strchr(line, LABEL_CHAR)) || (ft_strchr(line, ALT_COMMENT_CHAR) && ft_strchr(line, LABEL_CHAR)))
        {
            // if (ft_strlen(ft_strchr(line, COMMENT_CHAR)) > ft_strlen(ft_strchr(line, LABEL_CHAR))
            // || ft_strlen(ft_strchr(line, ALT_COMMENT_CHAR)) > ft_strlen(ft_strchr(line, LABEL_CHAR)))
                break;
        }
        // else if (line[j] != ' ' && line[j] != '\t')
        // {
            else if (line[j] == LABEL_CHAR)
            {
                valid_label(line, j, line_index);
                i = j;
                break;
            }
            else if (!ft_strchr(LABEL_CHARS, line[j]))
                break;
            // pos = ft_strchr(&line[j], LABEL_CHAR);
            // if (pos && ft_strchr(LABEL_CHARS, line[pos - &line[j] - 1]))
            // {
            //     valid_label(line, j, line_index);
            //     i = pos - &line[j];
            // }
            // break;
        // }
    }
    while (line[++i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
        ;
    if (!is_comment(line[i]) && line[i] != '\0')
        valid_operation(&line[i], line_index);
}

void valid_champ_file(t_list *champ, t_command *catalog)
{
    t_list *tmp;
    int i;
    int j;

    i = -1;
    tmp = champ;
    j = valid_head(champ);
    while (++i < j)
        tmp = tmp->next;
    while (tmp)
    {
        valid_command_line(tmp->content, i, catalog);
        // if (!tmp->next && ft_strlen((char *)(tmp->content)))
        //     show_error("Syntax error", -1);
        tmp = tmp->next;
        i++;
    }
}

int is_exist_label(t_list *code_list, char *label)
{
    t_list *mark_list;

    while (code_list)
    {
        // char *del = (char*)(((t_code *)(code_list->content))->mark)->content;
        mark_list = ((t_code *)(code_list->content))->mark;
        while (mark_list)
        {
            if (ft_strequ(mark_list->content, label))
                return (1);
            mark_list = mark_list->next;
        }
        code_list = code_list->next;
    }
    return (0);
}

void valid_existing_labels(t_list *code_list)
{
    t_list *tmp;
    t_code *code;
    char *lable;

    tmp = code_list;
    while (tmp)
    {
        code = (t_code *)tmp->content;
        if (code->arg1 && (lable = ft_strchr(code->arg1, LABEL_CHAR)) && !is_exist_label(code_list, &code->arg1[lable - code->arg1 + 1]))
            show_error("Label doesn't exist", -1);
        if (code->arg2 && (lable = ft_strchr(code->arg2, LABEL_CHAR)) && !is_exist_label(code_list, &code->arg2[lable - code->arg2 + 1]))
            show_error("Label doesn't exist", -1);
        if (code->arg3 && (lable = ft_strchr(code->arg3, LABEL_CHAR)) && !is_exist_label(code_list, &code->arg3[lable - code->arg3 + 1]))
            show_error("Label doesn't exist", -1);
        tmp = tmp->next;
    }
}