/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:34:35 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/18 13:34:36 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int		live_color(t_champ *player)
{
	if (MODULO(player->id) == MIN_PL) 
		return (COLOR_PAIR(LIVE(YELLOW_COL)) | A_UNDERLINE);
	else if (MODULO(player->id) == MIN_PL + 1)
		return (COLOR_PAIR(LIVE(RED_COL)) | A_UNDERLINE);
	else if (MODULO(player->id) == MAX_PL - 1)
		return (COLOR_PAIR(LIVE(GREEN_COL)) | A_UNDERLINE);
	else
		return (COLOR_PAIR(LIVE(BLUE_COL)) | A_UNDERLINE);
}

static int		g_attr(t_vm * vm, t_moves *mv, ssize_t cycle)
{
	if (cycle != vm->cycles_counter
	 	&& vm->cycles_to_die > 0
	 	&& mv->cycle_l > 0)
		mv->cycle_l--;
	if (cycle != vm->cycles_counter
		&& vm->cycles_to_die > 0
		&& mv->cycle_s > 0)
		mv->cycle_s--;
	if (mv->cycle_l)
		return (live_color(mv->champ_live));
	if (mv->cycle_s)
		return (COLOR_PAIR(mv->id) | A_BOLD);
	else
		return (COLOR_PAIR(mv->id));
}

void			make_map(t_vm *vm)
{
	static ssize_t	cycle = 0;
	int				i;
	int				j;
	int				attr;

	i = 0;
	while (i < BYTE_PER_LINE)
	{
		j = 0;
		wmove(vm->vs->map_window, i + 1, 3);
		while (j < BYTE_PER_LINE)
		{
			attr = g_attr(vm, &vm->vs->map[i * BYTE_PER_LINE + j], cycle);
			wattron(vm->vs->map_window, attr);
			wprintw(vm->vs->map_window, "%02x", vm->arena[i * BYTE_PER_LINE + j]);
			wattroff(vm->vs->map_window, attr);
			waddch(vm->vs->map_window, ' ');
			j++;
		}
		//wprintw(vm->vs->map_window, "\n");
		i++;
	}
	cycle = vm->cycles_counter;
}
