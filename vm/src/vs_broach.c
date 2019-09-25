/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vs_broach.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:41:34 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/12 13:44:39 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"
#include "corewar.h" 

void		update_map(t_vm *vm, t_carriage *carr, int addr, int size)
{
	int indicate;

	indicate = ((carr->parent->id - 1) % MAX_PL) + 1;
	while (size)
	{
		vm->vs->map[calc_addr(addr + size - 1)].id = indicate;
		vm->vs->map[calc_addr(addr + size - 1)].cycle_s = CYCLE_WAIT;
		size--;
	}
}

static void	free_visual(t_vs **vs)
{
	delwin((*vs)->info_window);
	delwin((*vs)->map_window);
	ft_memdel((void *)vs);
	endwin();
}

static void	visual_cycle(t_vm *vm)
{
	int		res;

	res = 1;
	if (!vm->vs->carriages_num)
	{
		//system("pkill afplay");
		vm->vs->is_run = false;
		//vm->vs->button = MUSIC;
		//voice_of_victory(vm);
	}
	if(cycle(vm) && res)
	{
		voice_of_game(vm);
		res = check(vm);
	}
}

void		vs_broach(t_vm *vm)
{
	vm->vs->quantity = get_quantity_players(vm->champs);
	config(vm);
	vm->vs->microsec = MICROSEC/vm->vs->speed;
	while ((vm->vs->button = getch()) != 27)
	{
		vm->vs->carriages_num = calc_carriages(vm);
		button(vm);
		if (vm->vs->button == 'd')
			visual_cycle(vm);
		else if(vm->vs->is_run)
		{
			visual_cycle(vm);
			usleep(vm->vs->microsec);
		}
		vm->vs->carriages_num = calc_carriages(vm);
		draw_vs(vm);
		if(vm->vs->button == SPACE)
			system("pkill afplay");
	}
	system("pkill afplay");
	free_visual(&(vm->vs));
}
