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

static void	free_visual(t_vs **vs)
{
	delwin((*vs)->info_window);
	delwin((*vs)->map_window);
	ft_memdel((void *)vs);
	endwin();
}

// static void	visual_cycle(t_vm *vm)
// {
// 	size_t cur_num;

// 	if (vm->cursors_num)
// 	{
// 		cycle(vm);
// 		if (vm->cycles_to_die == vm->cycles_after_check
// 			|| vm->cycles_to_die <= 0)
// 			cur_num = vm->cursors_num;
// 		if (!vm->cursors_num)
// 			vm->vs->is_run = false;
// 	}
// }

void		vs_broach(t_vm *vm)
{
	vm->vs = init_visual();
	vm->vs->carriages_num = calc_carriages(vm);
	//printf("carriages_num : %zu\n", vm->vs->carriages_num);
	vm->vs->quantity = get_quantity_players(vm->champs);
	config(vm);
	vm->vs->microsec = MICROSEC/vm->vs->speed;
	while ((vm->vs->button = getch()) != 27)
	{
		//printf("%i\n",byte_to_int(vm->arena) );
		button(vm);
		// if (vm->vs-> button == 'd')
		// 	visual_cycle(vm);
		// else if(vm->vs->is_run)
		// {
		// 	visual_cycle(vm);
		// 	usleep(vm->vs->microsec);
		// }
		printf("carriages_num : %zu\n", vm->vs->carriages_num);
		draw_vs(vm);
	}
	free_visual(&(vm->vs));
}
