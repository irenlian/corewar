/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:55:34 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:55:35 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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
