/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:41:29 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/18 13:41:31 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	show_winner(t_vm *vm)
{
	vm->vs->pixels += 2;
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels,
			INDENT, "The winner is ");
	wattron(vm->vs->info_window, COLOR_PAIR(vm->last_live->id));
	wprintw(vm->vs->info_window, "%.36s", vm->last_live->id); //PARSE NAME
	wattroff(vm->vs->info_window, COLOR_PAIR(vm->last_live->id));
}

void		make_info_window(t_vm *vm)
{
		show_run_status(vm);
		show_champs(vm);
		show_params(vm);
		show_help(vm);
	if (!vm->vs->quantity)
		show_winner(vm); 
}
