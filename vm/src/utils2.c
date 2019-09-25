/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 15:19:15 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/17 15:19:16 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "corewar.h"

void	button(t_vm *vm)
{
	if (vm->vs->button == SPACE)
		vm->vs->is_run = !(vm->vs->is_run);
	else if (vm->vs->button == MUSIC)
		vm->vs->sounds = !(vm->vs->sounds);
	else if (vm->vs->button == 'i')
		vm->vs->speed += 10;
	else if (vm->vs->button == 'u') 
		vm->vs->speed += 100;
	else if (vm->vs->button == 'y')
		vm->vs->speed -= 10;
	else if (vm->vs->button == 't')
		vm->vs->speed -= 100;
	vm->vs->speed = (vm->vs->speed < 1) ? 1 : vm->vs->speed;
	vm->vs->speed = (vm->vs->speed > 1000) ? 1000 : vm->vs->speed;
	vm->vs->microsec = MICROSEC / vm->vs->speed;
}
