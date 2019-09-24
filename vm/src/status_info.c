/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 14:37:25 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/18 14:37:26 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		show_run_status(t_vm *vm)
{
	vm->vs->pixels = 2;
	if(!vm->vs->is_run)
	{
		
		wattron(vm->vs->info_window, COLOR_PAIR((vm->vs->carriages_num) ? CYAN_COL : BLUE_COL));
		mvwprintw(vm->vs->info_window,
			vm->vs->pixels, INDENT, "%s",(vm->vs->quantity) ? "PAUSED" : "ISN'T RUN");
		wattroff(vm->vs->info_window, COLOR_PAIR((vm->vs->carriages_num) ? CYAN_COL : BLUE_COL));
	}
	else
	{
		wattron(vm->vs->info_window, COLOR_PAIR(RED_COL) | A_BOLD);
		mvwprintw(vm->vs->info_window, vm->vs->pixels += 0,
				1, "%s", " ______ _____ _____  _   _ _____ _____ _   _ _____ ");
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				1, "%s", "|  ___|_   _|  __ \\| | | |_   _|_   _| \\ | |  __ \\"); 
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				1, "%s", "| |_    | | | |  \\/| |_| | | |   | | |  \\| | |  \\/");
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				1, "%s", "|  _|   | | | | __ |  _  | | |   | | | . ` | | __ ");
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				1, "%s", "| |    _| |_| |_\\ \\| | | | | |  _| |_| |\\  | |_\\ \\");
			mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
				1, "%s", "\\_|    \\___/ \\____/\\_| |_/ \\_/  \\___/\\_| \\_/\\____/");
		wattroff(vm->vs->info_window, COLOR_PAIR(RED_COL) | A_BOLD);
	}
}

void		show_data_status(t_vm *vm)
{
	wattron(vm->vs->info_window, COLOR_PAIR(RED_COL) | A_BOLD);
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 2,
			INDENT_CENTER, "SPEED: %d", vm->vs->speed);
	wattron(vm->vs->info_window, COLOR_PAIR(CYAN_COL) | A_BOLD);
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 2,
			INDENT, "CYCLES : %10zd", vm->cycles_counter);
	wattron(vm->vs->info_window, COLOR_PAIR(YELLOW_COL) | A_BOLD);
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
			INDENT, "CARRIAGES : %zu", vm->vs->carriages_num);
	//NEED DATA
	wattroff(vm->vs->info_window, COLOR_PAIR(YELLOW_COL) | A_BOLD);
}

void	show_params(t_vm *vm)
{
	show_data_status(vm);
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 3, INDENT,
			"%-20s %zd", "Cycle to die :", vm->cycles_to_die);
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 2, INDENT,
			"%-20s %zu", "Cycle delta :", CYCLE_DELTA);
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 2, INDENT,
			"%-20s %zu", "Lives since check :", vm->live_counter);
		mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 1, INDENT,
			"%-20s %zu", "number live :", NBR_LIVE);
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 2, INDENT,
			"%-20s %zu", "Cycles to check :", (vm->cycles_to_die > 0) ?
			vm->cycles_to_die - vm->cycles_till_next_check : 0);
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 1, INDENT,
			"%-20s %zu", "Checks :", vm->check_counter);
	mvwprintw(vm->vs->info_window,
			vm->vs->pixels += 2, INDENT,
			"%-20s %zu", "Max check :", MAX_CHECKS);
}