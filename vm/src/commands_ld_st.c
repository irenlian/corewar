/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_ld_st.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:53:28 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:53:30 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

void	store(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	short			arg_sh_int;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_reg(arg_code, FIRST) &&
	is_valid_reg(vm, arg_i(car, arg_code, FIRST))) &&
	((is_t_reg(arg_code, SECOND) &&
	is_valid_reg(vm, arg_i(car, arg_code, SECOND))) ||
	is_t_ind(arg_code, SECOND))))
		return (pass_op(vm, car, arg_code));
	if (is_t_ind(arg_code, SECOND))
	{
		arg_sh_int = (short)byte_to_int(vm->arena,
			arg_i(car, arg_code, SECOND), IND) % IDX_MOD;
		write_int(vm->arena, calc_i(car->location + arg_sh_int),
			car->registers[get_i(vm->arena,
			arg_i(car, arg_code, FIRST)) - 1], DIR);
		if (vm->vs)
			update_map(vm, car, calc_i(car->location + arg_sh_int),
				car->op->dir_size);
	}
	else if (is_t_reg(arg_code, SECOND))
		car->registers[get_i(vm->arena, arg_i(car, arg_code, SECOND)) - 1] =
		car->registers[get_i(vm->arena, arg_i(car, arg_code, FIRST)) - 1];
	pass_op(vm, car, arg_code);
}

void	store_index(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			pos;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_reg(arg_code, FIRST) &&
	is_valid_reg(vm, arg_i(car, arg_code, FIRST))) &&
	((is_t_reg(arg_code, SECOND) &&
	is_valid_reg(vm, arg_i(car, arg_code, SECOND))) ||
	is_t_dir(arg_code, SECOND) || is_t_ind(arg_code, SECOND)) &&
	((is_t_reg(arg_code, THIRD) &&
	is_valid_reg(vm, arg_i(car, arg_code, THIRD))) ||
	is_t_dir(arg_code, THIRD))))
		return (pass_op(vm, car, arg_code));
	pos = calc_i((get_arg(vm, car, SECOND, 1) +
		get_arg(vm, car, THIRD, 1)) % IDX_MOD) + car->location;
	write_int(vm->arena, pos, get_arg(vm, car, FIRST, 0), DIR);
	pass_op(vm, car, arg_code);
	if (vm->vs)
		update_map(vm, car, pos, car->op->dir_size);
}

void	load(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			arg_int;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	(is_t_reg(arg_code, SECOND) &&
	is_valid_reg(vm, arg_i(car, arg_code, SECOND)))))
		return (pass_op(vm, car, arg_code));
	arg_int = get_arg(vm, car, FIRST, ft_strequ(car->op->name, "ld"));
	car->registers[get_i(vm->arena,
		arg_i(car, arg_code, SECOND)) - 1] = arg_int;
	car->carry = (car->registers[get_i(vm->arena,
		arg_i(car, arg_code, SECOND)) - 1] == 0) ? 1 : 0;
	pass_op(vm, car, arg_code);
}

void	load_index(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			pos;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	pos = 0;
	if (!(((is_t_reg(arg_code, FIRST) &&
	is_valid_reg(vm, arg_i(car, arg_code, FIRST))) ||
	is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	((is_t_reg(arg_code, SECOND) &&
	is_valid_reg(vm, arg_i(car, arg_code, SECOND)))
	|| is_t_dir(arg_code, SECOND)) && (is_t_reg(arg_code, THIRD) &&
	is_valid_reg(vm, arg_i(car, arg_code, THIRD)))))
		return (pass_op(vm, car, arg_code));
	pos = get_arg(vm, car, FIRST, 1) + get_arg(vm, car, SECOND, 1);
	if (ft_strequ(car->op->name, "ldi"))
		pos %= IDX_MOD;
	pos = calc_i(pos + car->location);
	res = (unsigned int)byte_to_int(vm->arena, pos, DIR);
	car->registers[get_i(vm->arena, arg_i(car, arg_code, THIRD)) - 1] = res;
	if (ft_strequ(car->op->name, "lldi"))
		car->carry = (res == 0) ? 1 : 0;
	pass_op(vm, car, arg_code);
}
