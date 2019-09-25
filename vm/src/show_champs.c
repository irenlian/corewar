/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:38:14 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/19 14:38:15 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void		show_players_win(t_vm *vm)
{
		wattron(vm->vs->info_window, COLOR_PAIR(CYAN_COL) | A_BOLD);
		mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
			0, "%s", "_____________________________________________________");
	wattron(vm->vs->info_window, COLOR_PAIR(BLUE_COL) | A_BOLD);
	mvwprintw(vm->vs->info_window, vm->vs->pixels += 1,
		INDENT_CENTER, "%s", ".-.| .-. . ..-,.-..-");
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_CENTER, "%s", "|-''-`-`-'-|`'-'  -'"); 
	mvwprintw(vm->vs->info_window, vm->vs->pixels += ONE,
		INDENT_CENTER, "%s", "'        `-'        ");
	wattroff(vm->vs->info_window, COLOR_PAIR(BLUE_COL) | A_BOLD);
}

void		show_champs(t_vm *vm) 
{
	int			champ;
	t_champ 	*damn;


	damn = vm->champs;
	champ = 0;
	while (champ < vm->vs->quantity)
	{
		//printf("vm->champs->id: %d\n", damn->id);
		 wattron(vm->vs->info_window, COLOR_PAIR(damn->id) | A_BOLD);
		wprintw(vm->vs->info_window, "\n");
		mvwprintw(vm->vs->info_window,vm->vs->pixels += 1, INDENT - 3,
			"%.50s\n", damn->header->prog_name);
		// mvwprintw(vm->vs->info_window,
		// 		vm->vs->pixels += 1, INDENT,
		// 		"%-32s %zd", "   Last live :", damn[champ]->last_live);
		// // mvwprintw(vm->vs->info_window,
		// // 		vm->vs->pixels += 1, INDENT,
		// // 		"%-32s %zu", "   Lives in current period :",
		// //		damn[champ]->current_lives_num); 
 
		// // NEED DATE
		wattroff(vm->vs->info_window, COLOR_PAIR(damn->id) | A_BOLD);
		champ++;
		damn = damn->next_champ;
	}
}
