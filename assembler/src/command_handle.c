#include "corewar.h"

t_command    *add_command_catalog()
{
    t_command  *tmp;
    t_command  *tmp2;

    tmp = (t_command*)malloc(sizeof(t_command));
    *tmp = (t_command){"aff", 16, 2, 0, 1, NULL};
    tmp2 = (t_command*)malloc(sizeof(t_command));
    *tmp2 = (t_command){"lfork", 15, 1000, 0, 0, tmp};
    tmp = (t_command*)malloc(sizeof(t_command));
    *tmp = (t_command){"lldi", 14, 50, 1, 1, tmp2};
    tmp2 = (t_command*)malloc(sizeof(t_command));
    *tmp2 = (t_command){"lld", 13, 10, 1, 1, tmp};
    tmp = (t_command*)malloc(sizeof(t_command));
    *tmp = (t_command){"fork", 12, 800, 0, 0, tmp2};
    tmp2 = (t_command*)malloc(sizeof(t_command));
    *tmp2 = (t_command){"sti", 11, 25, 0, 1, tmp};
    tmp = (t_command*)malloc(sizeof(t_command));
    *tmp = (t_command){"ldi", 10, 25, 0, 1, tmp2};
    return (tmp);
}

t_command *get_commad_catalog()
{
    t_command  *tmp;
    t_command  *tmp2;

    tmp = add_command_catalog();
    tmp2 = (t_command*)malloc(sizeof(t_command));
    *tmp2 = (t_command){"zjmp", 9, 20, 0, 0, tmp};
    tmp = (t_command*)malloc(sizeof(t_command));
    *tmp = (t_command){"xor", 8, 6, 1, 1, tmp2};
    tmp2 = (t_command*)malloc(sizeof(t_command));
    *tmp2 = (t_command){"or", 7, 6, 1, 1, tmp};
    tmp = (t_command*)malloc(sizeof(t_command));
    *tmp = (t_command){"and", 6, 6, 1, 1, tmp2};
    tmp2 = (t_command*)malloc(sizeof(t_command));
    *tmp2 = (t_command){"sub", 5, 10, 1, 1, tmp};
    tmp = (t_command*)malloc(sizeof(t_command));
    *tmp = (t_command){"add", 4, 10, 1, 1, tmp2};
    tmp2 = (t_command*)malloc(sizeof(t_command));
    *tmp2 = (t_command){"st", 3, 5, 0, 1, tmp};
    tmp = (t_command*)malloc(sizeof(t_command));
    *tmp = (t_command){"ld", 2, 5, 1, 1, tmp2};
    tmp2 = (t_command*)malloc(sizeof(t_command));
    *tmp2 = (t_command){"live", 1 ,10, 0, 0, tmp};
    return (tmp2);
}

t_command *get_com_byname(t_command *all, char *name)
{
    while (all)
    {
        if (ft_strequ(all->name, name))
            return (all);
        all = all->next;
    }
    return (NULL);
}

void    free_com_catalog(t_command *all)
{
    t_command *tmp;

    while (all)
    {
        tmp = all;
        all = all->next;
        free(tmp);
    }
}