/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 00:49:30 by ilian             #+#    #+#             */
/*   Updated: 2019/09/26 00:49:32 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int32_t		byte_to_int(unsigned char *arena, int32_t location, int length)
{
	// char			*tmp;
	// long long		*num;
	int32_t		res;
	_Bool		sign;
	int			i;
	
	res = 0;
	sign = !!(arena[calc_i(location)] & 0x80);
	i = 0;
	// while (length)
	// {
	// 	if (sign)
	// 		res += ((arena[calc_i(location + length - 1)] ^ 0xFF) << (i++ * 8));
	// 	else
	// 		res += arena[calc_i(location + length - 1)] << (i++ * 8);
	// 	length--;
	// }
	while (length && sign)
		res += ((arena[calc_i(location + length-- - 1)] ^ 0xFF) << (i++ * 8));
	while (length && !sign)
		res += arena[calc_i(location + length-- - 1)] << (i++ * 8);
	if (sign)
		res = ~(res);
	return (res);

	// tmp = ft_strnew(sizeof(long long) - 1);
	// if (length == DIR)
	// {
	// 	tmp[0] = str[3];
	// 	tmp[1] = str[2];
	// 	tmp[2] = str[1];
	// 	tmp[3] = str[0];
	// }
	// else if (length == IND)
	// {
	// 	tmp[0] = str[1];
	// 	tmp[1] = str[0];
	// }
	// num = (long long*)ft_memalloc(sizeof(long long));
	// ft_memcpy(num, tmp, sizeof(long long));
	// free(tmp);
	// res = *num;
	// free(num);
	// return (res);
}

// unsigned int	read_t_dir(unsigned char *arena, int arg_location, t_carriage *car)
// {
// 	// if (car->op->dir_size == IND)
// 		return (byte_to_int((char*)&arena[arg_location], car->op->dir_size));
// 	// else if (car->op->dir_size == DIR)
// 	// 	return (byte_to_int((char*)&arena[arg_location], car->op->dir_size));
// 	// else
// 	// 	return (0);
// }

void		write_int(unsigned char *arena, unsigned int arg_location, unsigned int value, int length)
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

int32_t	get_arg(t_vm *vm, t_carriage *car, int arg_i, int idx_mod)
{
	int32_t			arg_int;
	int32_t			value;
	char			*arg_code;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (car->op->codage_octal && is_t_reg(arg_code, arg_i) && is_valid_reg(vm, arg_index(car, arg_code, arg_i)))
		value = car->registers[get_i(vm->arena, arg_index(car, arg_code, arg_i)) - 1];
	else if (car->op->codage_octal && is_t_dir(arg_code, arg_i))
		value = byte_to_int(vm->arena, arg_index(car, arg_code, arg_i), car->op->dir_size);
	else if (car->op->codage_octal && is_t_ind(arg_code, arg_i))
	{
		arg_int = byte_to_int(vm->arena, arg_index(car, arg_code, arg_i), IND);
		value = byte_to_int(vm->arena, calc_i(car->location + (idx_mod ? (arg_int % IDX_MOD) : arg_int)), DIR);
	}
	else
		value = byte_to_int(vm->arena, to_codage(car), car->op->dir_size);
	free(arg_code);
	return (value);
}
