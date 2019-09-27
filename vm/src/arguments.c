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

long long	byte_to_int(char *str, int length)
{
	char			*tmp;
	long long		*num;
	long long		res;

	tmp = ft_strnew(sizeof(long long) - 1);
	if (length == DIR)
	{
		tmp[0] = str[3];
		tmp[1] = str[2];
		tmp[2] = str[1];
		tmp[3] = str[0];
	}
	else if (length == IND)
	{
		tmp[0] = str[1];
		tmp[1] = str[0];
	}
	num = (long long*)ft_memalloc(sizeof(long long));
	ft_memcpy(num, tmp, sizeof(long long));
	free(tmp);
	res = *num;
	free(num);
	return (res);
}

unsigned int	read_t_dir(unsigned char *arena, int arg_location, t_carriage *car)
{
	// if (car->op->dir_size == IND)
		return (byte_to_int((char*)&arena[arg_location], car->op->dir_size));
	// else if (car->op->dir_size == DIR)
	// 	return (byte_to_int((char*)&arena[arg_location], car->op->dir_size));
	// else
	// 	return (0);
}

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

unsigned int	get_arg(t_vm *vm, t_carriage *car, int arg_i, char *arg_code)
{
	short			arg_sh_int;

	if (is_t_reg(arg_code, arg_i) && is_valid_reg(vm, arg_index(car, arg_code, arg_i)))
		return (car->registers[get_i(vm->arena, arg_index(car, arg_code, arg_i)) - 1]);
	else if (is_t_dir(arg_code, arg_i))
		return (byte_to_int((char*)&vm->arena[arg_index(car, arg_code, arg_i)], car->op->dir_size));
	else if (is_t_ind(arg_code, arg_i))
	{
		arg_sh_int = (short)byte_to_int((char*)&vm->arena[arg_index(car, arg_code, arg_i)], IND) % IDX_MOD;
		return (byte_to_int((char*)&vm->arena[calc_i(car->location + arg_sh_int)], car->op->dir_size));
	}
	else
		return (0);
}
