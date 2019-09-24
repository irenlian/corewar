/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 16:11:38 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/17 16:11:39 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	clear_cursor(t_vm *vm, t_carriage *cursor)
{
	if (vm->vs->map[cursor->location].id >= CARRIAGE_NUM(0)
		&& vm->vs->map[cursor->location].id <= CARRIAGE_NUM(MAX_PL))
		vm->vs->map[cursor->location].id =
				PLAYER_NUM(vm->vs->map[cursor->location].id);
}

void	draw_cursor(t_vm *vm, t_carriage *cursor)
{
	if (vm->vs->map[cursor->location].id >= 0 && vm->vs->map[cursor->location].id <= MAX_PL)
		
		vm->vs->map[cursor->location].id = CARRIAGE_NUM(vm->vs->map[cursor->location].id);
}

int		calc_addr(int addr)
{
	addr %= MEM_SIZE;
	if (addr < 0)
		addr += MEM_SIZE;
	return (addr);
}
