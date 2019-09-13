/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:45:54 by ilian             #+#    #+#             */
/*   Updated: 2019/09/13 13:45:57 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

void    set_players_to_arena(t_champ *champ, char **arena)
{
    int i;
    int quantity;

    i = 0;
    quantity = get_quantity_players(champ);
    while(champ)
    {
        ft_memcpy(&arena[0][MEM_SIZE / quantity * i], champ->byte_code->code, champ->byte_code->length);
        champ = champ->next_champ;
        i++;
    }
}
