/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:43:29 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:54:13 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		cycle(t_vm *vm)
{
	t_carriage	*car;

	car = vm->cars;
	vm->cycles_counter++;
	while (car)
	{
		if (car->cycles_to_run == 0)
		{
			car->op = get_com_by_code(vm->catalog,
				get_i(vm->arena, car->location));
			car->cycles_to_run = car->op ? car->op->cycles : 0;
			if (!car->op)
				pass_op(vm, car, NULL);
		}
		if (car->cycles_to_run)
			car->cycles_to_run--;
		if (car->cycles_to_run == 0 && car->op && car->op->func)
			car->op->func(vm, car);
		car = car->next;
	}
	vm->cycles_till_next_check--;
	return (1);
}

void	clean_carriages(t_vm *vm)
{
	t_carriage	*car;
	t_carriage	*prev;
	t_carriage	*tmp;

	car = vm->cars;
	prev = NULL;
	while (car)
	{
		if (!car->live)
		{
			tmp = car;
			if (prev)
				prev->next = car->next;
			else
				vm->cars = car->next;
			car = car->next;
			free(tmp);
		}
		else
		{
			car->live = 0;
			prev = car;
			car = car->next;
		}
	}
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
	clean_carriages(vm);
	if (!vm->cars)
		return (0);
	vm->cycles_till_next_check = vm->cycles_to_die;
	return (1);
}
