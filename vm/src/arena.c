/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:45:54 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:34:51 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_players_to_arena(t_champ *champ, char **arena)
{
	int i;
	int quantity;

	i = 0;
	quantity = get_quantity_players(champ);
	while (champ)
	{
		ft_memcpy(&arena[0][MEM_SIZE / quantity * i],
		champ->byte_code->code, champ->byte_code->length);
		champ = champ->next_champ;
		i++;
	}
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

void	pass_op(t_vm *vm, t_carriage *car, char *arg_code)
{
	if (!car->op)
		move_carriage(vm, car, car->location + 1);
	else if (car->op->codage_octal)
	{
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
