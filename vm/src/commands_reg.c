/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:53:46 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:53:47 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

void	addition(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (is_t_reg(arg_code, FIRST) &&
	is_valid_reg(vm, arg_i(car, arg_code, FIRST)) &&
	is_t_reg(arg_code, SECOND) &&
	is_valid_reg(vm, arg_i(car, arg_code, SECOND)) &&
	is_t_reg(arg_code, THIRD) &&
	is_valid_reg(vm, arg_i(car, arg_code, THIRD)))
	{
		res = car->registers[get_i(vm->arena, arg_i(car, arg_code, FIRST)) - 1]
		+ car->registers[get_i(vm->arena, arg_i(car, arg_code, SECOND)) - 1];
		car->registers[get_i(vm->arena, arg_i(car, arg_code, THIRD)) - 1] = res;
		car->carry = (res == 0) ? 1 : 0;
	}
	pass_op(vm, car, arg_code);
}

void	substraction(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (is_t_reg(arg_code, FIRST) &&
	is_valid_reg(vm, arg_i(car, arg_code, FIRST)) &&
	is_t_reg(arg_code, SECOND) &&
	is_valid_reg(vm, arg_i(car, arg_code, SECOND)) &&
	is_t_reg(arg_code, THIRD) &&
	is_valid_reg(vm, arg_i(car, arg_code, THIRD)))
	{
		res = car->registers[get_i(vm->arena, arg_i(car, arg_code, FIRST)) - 1]
		- car->registers[get_i(vm->arena, arg_i(car, arg_code, SECOND)) - 1];
		car->registers[get_i(vm->arena, arg_i(car, arg_code, THIRD)) - 1] = res;
		car->carry = (res == 0) ? 1 : 0;
	}
	pass_op(vm, car, arg_code);
}

void	and_or_xor(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	res = 0;
	if (!(((is_t_reg(arg_code, FIRST) &&
	is_valid_reg(vm, arg_i(car, arg_code, FIRST))) ||
	is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	((is_t_reg(arg_code, SECOND) &&
	is_valid_reg(vm, arg_i(car, arg_code, SECOND))) ||
	is_t_dir(arg_code, SECOND) || is_t_ind(arg_code, SECOND)) &&
	(is_t_reg(arg_code, THIRD) &&
	is_valid_reg(vm, arg_i(car, arg_code, THIRD)))))
		return (pass_op(vm, car, arg_code));
	res = get_arg(vm, car, FIRST, 1);
	if (ft_strequ(car->op->name, "and"))
		res = res & get_arg(vm, car, SECOND, 1);
	else if (ft_strequ(car->op->name, "or"))
		res = res | get_arg(vm, car, SECOND, 1);
	else if (ft_strequ(car->op->name, "xor"))
		res = res ^ get_arg(vm, car, SECOND, 1);
	car->registers[get_i(vm->arena, arg_i(car, arg_code, THIRD)) - 1] = res;
	car->carry = (res == 0) ? 1 : 0;
	pass_op(vm, car, arg_code);
}
