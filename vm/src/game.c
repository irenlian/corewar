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

#include "corewar.h"

int		all_are_dead(t_vm *vm)
{
	return (0);
}

// void	read_args(t_vm *vm, t_carriage *car, t_command *com)
// {
// 	char			*arg_code;
// 	unsigned int	*arg_int;
// 	short			*arg_sh_int;
// 	int				i;

// 	i = 1;
// 	arg_int = 0;
// 	arg_sh_int = 0;
// 	arg_code = get_bits(vm->arena[car->location + i]);
// 	if (arg_code[0] == 1 && arg_code[1] == 0 && com->dir_size == 4)
// 	{
// 		i++;
// 		arg_int = (unsigned int*)ft_memalloc(sizeof(unsigned int));
// 		ft_memcpy(arg_int, car->location + i, com->dir_size);
// 		i += com->dir_size;
// 	}
// 	if ((arg_code[0] == 1 && arg_code[1] == 0 && com->dir_size == 2) || (arg_code[0] == 1 && arg_code[1] == 1))
// 	{
// 		i++;
// 		arg_sh_int = (short*)ft_memalloc(sizeof(short));
// 		ft_memcpy(arg_sh_int, car->location + i, com->dir_size);
// 		i += com->dir_size;
// 	}
// 	if (arg_code[2] == 0 && arg_code[3] == 1)
// 	{
// 		car->registers[car->location + i] = arg_int;
// 	}
// }

int		make_move(t_vm *vm, t_carriage *car)
{
	t_command	*com;
	
	if (car->op && car->op->func)
	{
		car->op->func(vm, car);
		if (!(ft_strequ(car->op->name, "zjmp") && car->carry == 1))
			pass_op(vm, car);
	}
	else
		car->location = calc_i(car->location + 1);
	car->op = get_com_by_code(vm->catalog, get_i(vm->arena, car->location));
	car->cycles_to_run = car->op ? car->op->cycles : 0;
	return (1);
}

int		cycle(t_vm *vm)
{
	t_carriage	*car;

	car = vm->cars;
	if (all_are_dead(vm))
		return (0);
	while (car)
	{
		if (car->cycles_to_run)
			car->cycles_to_run--;
		if (car->cycles_to_run == 0)
			make_move(vm, car);
		car = car->next;
	}
	vm->cycles_till_next_check--;
	return (1);
}

void	clean_carriages(t_vm *vm)
{
	t_carriage	*car;
	t_carriage	*prev;

	car = vm->cars;
	prev = NULL;
	while (car)
	{
		if (!car->live)
		{
			if (prev)
			{
				prev->next = car->next;
			}
			else
			{
				vm->cars = car->next;
			}
			car = car->next;
			//TODO: clean
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
	// ft_printf("Carriages number: %i\n", calc_carriages(vm));
	return (1);
}
