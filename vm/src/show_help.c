/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 21:35:20 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/19 21:35:22 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		draw_help_win(t_vm *vm)
{
			wattron(vm->vs->info_window, COLOR_PAIR(CYAN_COL) | A_BOLD);
		mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
			0, "%s", "_____________________________________________________");
	wattron(vm->vs->info_window, COLOR_PAIR(RED_COL) | A_BOLD);
		mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				INDENT + 3, "%s", " _          _       ");
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				INDENT + 3, "%s", "| |__   ___| |_ __  "); 
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				INDENT + 3, "%s", "| '_ \\ / _ \\ | '_ \\ ");
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				INDENT + 3, "%s", "| | | |  __/ | |_) |");
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				INDENT + 3, "%s", "|_| |_|\\___|_| .__/ ");
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				INDENT + 3, "%s", "             |_|    ");
		wattroff(vm->vs->info_window, COLOR_PAIR(RED_COL) | A_BOLD);
}

void		show_help(t_vm *vm)
{
	wattron(vm->vs->info_window, COLOR_PAIR(CYAN_COL));
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 2, INDENT,
			"Start/Pause - 'SPACE");
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 2, INDENT,
			"Debug mode (pass one cycle) - 'D'");
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 1, INDENT,
			"Choose your speed: ");
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 1, INDENT + 18,
			"I : +10 ");
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 1, INDENT + 18,
			"U : +100 ");
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 1, INDENT + 18,
			"Y : -10 ");
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 1, INDENT + 18,
			"T : -100 ");
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 1, INDENT,
			"Sounds ON/OFF - 'M'");
	wattroff(vm->vs->info_window, COLOR_PAIR(CYAN_COL));
}