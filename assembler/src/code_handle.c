#include "corewar.h"

t_list  *get_code_by_mark(t_list  *code_list, char *mark)
{
    t_code *code;
    t_list *mark_list;

    while (code_list)
    {
        code = (t_code *)(code_list->content);
        mark_list = code->mark;
        if (mark_list)
        {
            while (mark_list)
            {
                if (ft_strequ(mark_list->content, mark))
                    return (code_list);
                mark_list = mark_list->next;
            }
        }
        code_list = code_list->next;
    }
    return (NULL);
}