/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:45:40 by ilian             #+#    #+#             */
/*   Updated: 2019/09/13 13:45:45 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int get_quantity_players(t_champ *champ)
{
    int size;

    size = 0;
    while (champ)
    {
        champ = champ->next_champ;
        size++;
    }
    return (size);
}

int	byte_to_int(char *str)
{
	char	*tmp;
	int		*num;
	int		res;

	tmp = ft_strnew(sizeof(int) - 1);
	tmp[0] = str[3];
	tmp[1] = str[2];
	tmp[2] = str[1];
	tmp[3] = str[0];
	num = (int*)ft_memalloc(sizeof(int));
	ft_memcpy(num, tmp, sizeof(int));
	free(tmp);
	res = *num;
	free(num);
	return (res);
}

char	*get_bits(unsigned char octet)
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

int		calc_i(int i)
{
	if (i >= 0 && i < MEM_SIZE)
		return (i);
	i %= MEM_SIZE;
	if (i < 0)
		i = MEM_SIZE + i;
	return (i);
}

char	get_i(char *arena, int i)
{
	return (arena[calc_i(i)]);
}

int		is_t_ind(char *arg_code, int arg_pos)
{
	if (arg_pos == 1 && arg_code[0] == '1' && arg_code[1] == '1')
		return (1);
	if (arg_pos == 2 && arg_code[2] == '1' && arg_code[3] == '1')
		return (1);
	if (arg_pos == 3 && arg_code[4] == '1' && arg_code[5] == '1')
		return (1);
	return (0);
}

int		is_t_dir(char *arg_code, int arg_pos)
{
	if (arg_pos == 1 && arg_code[0] == '1' && arg_code[1] == '0')
		return (1);
	if (arg_pos == 2 && arg_code[2] == '1' && arg_code[3] == '0')
		return (1);
	if (arg_pos == 3 && arg_code[4] == '1' && arg_code[5] == '0')
		return (1);
	return (0);
}

int		is_t_reg(char *arg_code, int arg_pos)
{
	if (arg_pos == 1 && arg_code[0] == '0' && arg_code[1] == '1')
		return (1);
	if (arg_pos == 2 && arg_code[2] == '0' && arg_code[3] == '1')
		return (1);
	if (arg_pos == 3 && arg_code[4] == '0' && arg_code[5] == '1')
		return (1);
	return (0);
}

int		is_valid_reg(t_vm *vm, int loc)
{
	return (get_i(vm->arena, loc) > 0 && get_i(vm->arena, loc) <= REG_NUMBER);
}

int		calc_args_length(char *arg_code, unsigned int num, int dir_size)
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

void	pass_op(t_vm *vm, t_carriage *car)
{
	char			*arg_code;

	arg_code = NULL;
	if (!car->op)
		car->location = calc_i(car->location + 1);
	else if (ft_strequ(car->op->name, "zjmp") && car->carry == 1)
		return ;
	else if (car->op->codage_octal)
	{
		arg_code = get_bits(get_i(vm->arena, to_codage(car)));
		car->location = calc_i(car->location + OP + car->op->codage_octal + 
			calc_args_length(arg_code, car->op->args_num, car->op->dir_size));
	}
	else
	{
		car->location = calc_i(car->location + OP + car->op->dir_size);
	}
}

int		calc_carriages(t_vm *vm)
{
	t_carriage	*car;
	int			num;

	car = vm->cars;
	num = 0;
	while (car)
	{
		num++;
		car = car->next;
	}
	return (num);
}