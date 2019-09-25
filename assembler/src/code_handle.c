#include "corewar.h"

t_list  *get_code_by_mark(t_list  *code_list, char *mark)
{
    t_code *code;

    while (code_list)
    {
        code = (t_code *)(code_list->content);
        if (code->mark)
        {
            while (code->mark)
            {
                if (ft_strequ(code->mark->content, mark))
                    return (code_list);
                code->mark = code->mark->next;
            }
        }
        code_list = code_list->next;
    }
    return (NULL);
}