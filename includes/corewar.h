#include <stdlib.h>
#include <fcntl.h>
#include "./op.h"
#include "../printf/includes/ft_printf.h"
#include "../get_next_line/get_next_line.h"

typedef struct l_champ
{
    int              id;
    char            *name;
    char            *coment;
    int             *champ_size;
    char            *code;
    struct l_champ  *next_champ;
}                   t_champ;

typedef struct l_str
{
    char            *line;
    struct l_str    *next;
}                   t_str;

t_str   *create_tstr(char *str);
t_champ   *create_lchamp();