#include "corewar.h"

t_code  *get_code_by_mark(t_code  *code, char *mark)
{
    while (code)
    {
        if (ft_strequ(mark, code->mark))
            return (code);
        code = code->next;
    }
    return (NULL);
}