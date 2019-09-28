/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:45:40 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:55:26 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_quantity_players(t_champ *champ)
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

int		show_error_vm(const char *error, t_vm *vm, int code)
{
	if (code == 1)
		ft_printf("%t%s%s%t\n", B_RED,
		"Usage of flag [[-n number] player_name]\n\"number\"",
		" is from 1 to maximum players quantity\n", EOC);
	else if (code == 2)
		ft_printf("%t%s%s%s%t\n", B_RED,
			"Can't read source file ", error, "\n", EOC);
	else
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
