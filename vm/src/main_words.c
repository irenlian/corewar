/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_words.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 20:31:08 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/25 20:31:13 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		show_fighting_win(t_vm *vm)
{
	wattron(vm->vs->info_window, COLOR_PAIR(RED_COL) | A_BOLD);
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 0,
		INDENT_ONE, "%s",
		" ______ _____ _____  _   _ _____ _____ _   _ _____ ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_ONE, "%s",
		"|  ___|_   _|  __ \\| | | |_   _|_   _| \\ | |  __ \\");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_ONE, "%s",
		"| |_    | | | |  \\/| |_| | | |   | | |  \\| | |  \\/");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_ONE, "%s",
		"|  _|   | | | | __ |  _  | | |   | | | . ` | | __ ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_ONE, "%s",
		"| |    _| |_| |_\\ \\| | | | | |  _| |_| |\\  | |_\\ \\");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_ONE, "%s",
		"\\_|    \\___/ \\____/\\_| |_/ \\_/  \\___/\\_| \\_/\\____/");
	wattroff(vm->vs->info_window, COLOR_PAIR(RED_COL) | A_BOLD);
}

void		show_end_win(t_vm *vm)
{
	wattron(vm->vs->info_window, COLOR_PAIR(BLUE_COL) | A_BOLD);
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 0,
		INDENT_CENTER + 5, "%s", " _____ _   _______ ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_CENTER + 5, "%s", "|  ___| \\ | |  _  \\");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_CENTER + 5, "%s", "| |__ |  \\| | | | |");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_CENTER + 5, "%s", "|  __|| . ` | | | |");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_CENTER + 5, "%s", "| |___| |\\  | |/ / ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_CENTER + 5, "%s", "\\____/\\_| \\_/___/  ");
	wattroff(vm->vs->info_window, COLOR_PAIR(BLUE_COL) | A_BOLD);
}

void		show_pause_win(t_vm *vm)
{
	wattron(vm->vs->info_window, COLOR_PAIR(GREEN_COL));
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 0, INDENT_THREE, "%s",
		"______  ___  _   _ _____ _____ ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE, INDENT_THREE, "%s",
			"| ___ \\/ _ \\| | | /  ___|  ___|");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE, INDENT_THREE, "%s",
		"| |_/ / /_\\ \\ | | \\ `--.| |__  ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE, INDENT_THREE, "%s",
			"|  __/|  _  | | | |`--. \\  __| ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE, INDENT_THREE, "%s",
		"| |   | | | | |_| /\\__/ / |___ ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE, INDENT_THREE, "%s",
		"\\_|   \\_| |_/\\___/\\____/\\____/ ");
	wattroff(vm->vs->info_window, COLOR_PAIR(GREEN_COL));
}
