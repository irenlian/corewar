#include "corewar.h"

t_list  *get_code_by_mark(t_list  *code_list, char *mark)
{
    t_code *code;
    t_list *iter;

    while (code_list)
    {
        code = (t_code *)(code_list->content);
        iter = code->mark;
        if (ft_strequ(mark, iter->content))
            return (code_list);
        code_list = code_list->next;
    }
    return (NULL);
}