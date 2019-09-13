/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:45:40 by ilian             #+#    #+#             */
/*   Updated: 2019/09/13 13:45:45 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int get_quantity_players(t_champ *champ)
{
    int size;

    size = 0;
    while (champ)
    {
        champ = champ->next_champ;
        size++;
    }
    return (size);
}

int	byte_to_int(char *str)
{
	char	*tmp;
	int		*num;
	int		res;

	tmp = ft_strnew(sizeof(int) - 1);
	tmp[0] = str[3];
	tmp[1] = str[2];
	tmp[2] = str[1];
	tmp[3] = str[0];
	num = (int*)ft_memalloc(sizeof(int));
	ft_memcpy(num, tmp, sizeof(int));
	free(tmp);
	res = *num;
	free(num);
	return (res);
}
