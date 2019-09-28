/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_lifetime.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:53:37 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:53:39 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

void	live(t_vm *vm, t_carriage *car)
{
	unsigned int	arg_int;
	t_champ			*player;

	arg_int = (unsigned int)get_arg(vm, car, to_codage(car), 0);
	player = vm->champs;
	while (player)
	{
		if (player->id * -1 == arg_int)
			break ;
		player = player->next_champ;
	}
	if (player)
		vm->last_live = player;
	vm->live_counter++;
	car->live = 1;
	pass_op(vm, car, NULL);
}

void	zjmp(t_vm *vm, t_carriage *car)
{
	int32_t		arg_int;
	t_champ		*player;

	if (car->carry != 1)
		return (pass_op(vm, car, NULL));
	arg_int = get_arg(vm, car, FIRST, 1);
	move_carriage(vm, car, car->location + arg_int % IDX_MOD);
}

void	lfork(t_vm *vm, t_carriage *car)
{
	int32_t			pos;
	t_carriage		*fork;

	pos = get_arg(vm, car, FIRST, 0);
	if (ft_strequ(car->op->name, "fork"))
		pos %= IDX_MOD;
	pos += car->location;
	fork = copy_carriage(vm, car);
	fork->location = calc_i(pos);
	pass_op(vm, car, NULL);
}

void	aff(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			arg_int;
	char			res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!(is_t_reg(arg_code, FIRST) &&
	is_valid_reg(vm, arg_i(car, arg_code, FIRST))))
		return (pass_op(vm, car, arg_code));
	arg_int = get_arg(vm, car, FIRST, 0);
	ft_printf("Aff: %c\n", (char)arg_int);
	pass_op(vm, car, arg_code);
}
