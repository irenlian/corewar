/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:13:06 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 19:13:07 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	normalize_id(t_champ *champ)
{
	int		i;

	i = 1;
	while (champ)
	{
		champ->id = i++;
		champ = champ->next_champ;
	}
}

int		insert_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*tmp;
	t_champ	*prev;
	int		i;

	tmp = vm->champs;
	prev = NULL;
	i = 0;
	while (tmp)
	{
		if (tmp->id >= champ->id)
		{
			champ->next_champ = tmp;
			if (prev)
				prev->next_champ = champ;
			else
				vm->champs = champ;
			if (tmp->id == champ->id)
				normalize_id(vm->champs);
			return (1);
		}
		prev = tmp;
		tmp = tmp->next_champ;
	}
	return (0);
}

int		push_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp->next_champ)
		tmp = tmp->next_champ;
	tmp->next_champ = champ;
	return (1);
}
