#include "corewar.h"

t_bytes   *create_byte(char* str)
{
    t_bytes     *tstr;
    int         i;
    int         j;

    j = 4;
    tstr = (t_bytes*)malloc(sizeof(t_bytes));
    tstr->next = NULL;
    if (str)
    {
        i = ft_strlen(str);
        while (--j >= 0)
        {
            if (i >= 0)
                tstr->byte[j] = str[i--];
            else
                tstr->byte[j] = '0';  
        }
    }
    else 
    {
        tstr->byte[0] = '0';
        tstr->byte[1] = '0';
        tstr->byte[2] = '0';
        tstr->byte[3] = '0';
    }
    tstr->byte[4] = '\0';
    return (tstr);
}