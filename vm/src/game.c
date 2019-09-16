/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:43:29 by ilian             #+#    #+#             */
/*   Updated: 2019/09/13 16:43:32 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int		all_are_dead(t_vm *vm)
{
	return (0);
}

int		make_move(t_vm *vm, t_carriage *car)
{
	if (is_existing(vm->arena[car->location]))
	{
		
	}
}

int		cycle(t_vm *vm)
{
	t_carriage	*car;

	car = vm->cars;
	if (all_are_dead(vm))
		return (0);
	while (car)
	{
		if (car->cycles_to_run == 0)
			make_move(vm, car);
		car->cycles_to_run--;
		car = car->next;
	}
	vm->cycles_till_next_check--;
	return (1);
}

int		check(t_vm *vm)
{
	if (vm->cycles_till_next_check > 0)
		return (1);
	if (vm->cycles_to_die <= 0)
		return (0);
	if (vm->live_counter >= NBR_LIVE || vm->check_counter >= MAX_CHECKS)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->check_counter = 0;
	}
	vm->check_counter++;
	vm->checks_from_start++;
	vm->live_counter = 0;
	return (0);
}
