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

void		show_authors(t_vm *vm)
{
	wattron(vm->vs->info_window, COLOR_PAIR(RED_COL));
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 2,
		INDENT_CENTER + 19, "%s", " A U T O R S :"); 
	wattron(vm->vs->info_window, COLOR_PAIR(BLUE_COL) | A_BOLD);
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 2,
		INDENT_CENTER + 20, "%s", "ILIAN DLIAN");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
		INDENT_CENTER + 20, "%s", "PPOLOZHE PDEMIAN");
	wattroff(vm->vs->info_window, COLOR_PAIR(BLUE_COL) | A_BOLD);
}

void	draw_winner(t_vm *vm, int index)
{
	wattron(vm->vs->info_window, COLOR_PAIR(index) | A_BOLD);
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
		INDENT_CENTER - 4, "%s", "__    __ _  __  _  __  _  ____ _____ ");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
		INDENT_CENTER - 4, "%s", "\\ \\/\\/ /| ||  \\| ||  \\| || ===|| () )");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
		INDENT_CENTER - 4, "%s", "  \\_/\\/ |_||_|\\__||_|\\__||____||_|\\_\\");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 2,
		INDENT_CENTER + 8, "%s", (index != GREY) ? 
			(vm->last_live->header->prog_name) : ".....");
	wattroff(vm->vs->info_window, COLOR_PAIR(index) | A_BOLD);
}

void		make_info_window(t_vm *vm)
{
	show_run_status(vm);
	show_players_win(vm);
	show_champs(vm);
	draw_info_win(vm);
	show_params(vm);
	draw_help_win(vm);
	show_help(vm);
	if (vm->last_live && !check(vm))
	{
		voice_of_victory(vm);
		draw_winner(vm, vm->last_live->id);
	}
	else
		draw_winner(vm, GREY);
	show_authors(vm);
}
