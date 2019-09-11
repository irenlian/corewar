#include "corewar.h"

t_str   *create_tstr(char *str)
{
    t_str   *tstr;

    tstr = (t_str*)malloc(sizeof(t_str));
    tstr->line = str;
    tstr->next = NULL;
    return (tstr);
}

t_champ   *create_lchamp()
{
    t_champ   *lchamp;

    lchamp = (t_champ*)malloc(sizeof(t_champ));
    lchamp->champ_size = 0;
    lchamp->name = "";
    lchamp->id = 0;
    lchamp->coment = "";
    lchamp->code = "0b68 0100 0700 0101 0000 0000 0290 0000 0000 0209 ffed";
    lchamp->next_champ = NULL;
    return (lchamp);
}