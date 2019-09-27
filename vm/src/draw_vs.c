/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:50:01 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/17 18:50:02 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void	show_border(WINDOW *win)
{
	wattron(win, COLOR_PAIR(CYAN_COL));
	box(win, 0, 0);
	wattroff(win, COLOR_PAIR(CYAN_COL));
}

void		draw_vs(t_vm *vm)
{
	werase(vm->vs->map_window);
	werase(vm->vs->info_window);
	make_map(vm);
	make_info_window(vm);
	show_border(vm->vs->map_window);
	show_border(vm->vs->info_window);
	wrefresh(vm->vs->info_window);
	wrefresh(vm->vs->map_window);
}
