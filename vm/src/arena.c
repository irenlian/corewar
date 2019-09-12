#include "../../includes/corewar.h"

void    set_players_to_arena(t_champ *champ, char **arena)
{
    int i;
    int quantity;

    i = 0;
    quantity = get_quantity_players(champ);
    while(champ)
    {
        ft_memcpy(&arena[0][MEM_SIZE / quantity * i], champ->code, ft_strlen(champ->code));
        champ = champ->next_champ;
        i++;
    }
}