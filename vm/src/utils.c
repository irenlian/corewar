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
#include "stdio.h"

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
	i %= MEM_SIZE;
	if (i < 0)
		i += MEM_SIZE;
	return (i);
}

char	get_i(unsigned char *arena, int i)
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

void	pass_op(t_vm *vm, t_carriage *car, char *arg_code)
{
	if (!car->op)
		move_carriage(vm, car, car->location + 1);
	// else if (ft_strequ(car->op->name, "zjmp") && car->carry == 1)
	// 	return ;
	else if (car->op->codage_octal)
	{
		// arg_code = get_bits(get_i(vm->arena, to_codage(car)));
		move_carriage(vm, car, car->location + OP + car->op->codage_octal + 
			calc_args_length(arg_code, car->op->args_num, car->op->dir_size));
	}
	else
		move_carriage(vm, car, car->location + OP + car->op->dir_size);
	if (arg_code)
		free(arg_code);
}

void	move_carriage(t_vm *vm, t_carriage *car, int new_location)
{
	if (vm->vs)
		clear_cursor(vm, car);
	car->location = calc_i(new_location);
	if (vm->vs)
		draw_cursor(vm, car);
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

int			show_error_vm(const char *error, t_vm *vm)
{
    ft_printf("%t%s%t\n", B_RED, error, EOC);
	if (vm && vm->leaks)
		system("leaks -q corewar");
	exit(1);
}

int		is_str_digits(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	print_arena(t_vm *vm)
{
	int		i;

	i = 0;
	ft_printf("0x%#0.4x : ", i);
	while (i < MEM_SIZE)
	{
		if (i % DUMP_LENGTH == 0 && i)
			ft_printf("%#0.4x : ", i);
		ft_printf("%02x ", vm->arena[i++]);
		if (i % DUMP_LENGTH == 0)
			ft_printf("\n");
	}
	if (vm->leaks)
		system("leaks -q corewar");
	exit(0);
}