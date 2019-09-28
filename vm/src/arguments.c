/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 00:49:30 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:34:59 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int32_t		byte_to_int(unsigned char *arena, int32_t location, int length)
{
	int32_t		res;
	_Bool		sign;
	int			i;

	res = 0;
	sign = !!(arena[calc_i(location)] & 0x80);
	i = 0;
	while (length && sign)
		res += ((arena[calc_i(location + length-- - 1)] ^ 0xFF) << (i++ * 8));
	while (length && !sign)
		res += arena[calc_i(location + length-- - 1)] << (i++ * 8);
	if (sign)
		res = ~(res);
	return (res);
}

void		write_int(unsigned char *arena,
	unsigned int arg_location, unsigned int value, int length)
{
	if (length == DIR)
	{
		arg_location %= MEM_SIZE;
		arena[arg_location++] = value >> (3 * 8);
		arg_location %= MEM_SIZE;
		arena[arg_location++] = value >> (2 * 8);
	}
	arg_location %= MEM_SIZE;
	arena[arg_location++] = value >> (8);
	arg_location %= MEM_SIZE;
	arena[arg_location] = value;
}

int32_t		get_arg(t_vm *vm, t_carriage *car, int argi, int idx_mod)
{
	int32_t			arg_int;
	int32_t			value;
	char			*arg_code;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (car->op->codage_octal && is_t_reg(arg_code, argi)
		&& is_valid_reg(vm, arg_i(car, arg_code, argi)))
		value = car->registers[get_i(vm->arena,
			arg_i(car, arg_code, argi)) - 1];
	else if (car->op->codage_octal && is_t_dir(arg_code, argi))
		value = byte_to_int(vm->arena, arg_i(car, arg_code, argi),
			car->op->dir_size);
	else if (car->op->codage_octal && is_t_ind(arg_code, argi))
	{
		arg_int = byte_to_int(vm->arena, arg_i(car, arg_code, argi), IND);
		value = byte_to_int(vm->arena, calc_i(car->location +
			(idx_mod ? (arg_int % IDX_MOD) : arg_int)), DIR);
	}
	else
		value = byte_to_int(vm->arena, to_codage(car), car->op->dir_size);
	free(arg_code);
	return (value);
}

char		*get_bits(unsigned char octet)
{
	char	*res;
	int		i;

	i = 7;
	res = ft_strnew(8);
	while (octet > 1)
	{
		if (octet % 2 == 0)
			res[i] = '0';
		else
			res[i] = '1';
		octet = octet / 2;
		i--;
	}
	if (octet == 1)
		res[i] = '1';
	else
		res[i] = '0';
	while (--i >= 0)
		res[i] = '0';
	return (res);
}

int			calc_args_length(char *arg_code, unsigned int num, int dir_size)
{
	int		res;
	int		i;

	res = 0;
	i = 1;
	if (num > 3)
		return (res);
	while (num >= i)
	{
		if (is_t_ind(arg_code, i))
			res += IND;
		if (is_t_reg(arg_code, i))
			res += REG;
		if (is_t_dir(arg_code, i))
			res += dir_size;
		i++;
	}
	return (res);
}
