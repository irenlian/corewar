/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:53:19 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/12 13:53:30 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static void		do_map(t_vm *vm)
{
	int			id_player;
	int			val;
	int			sit;
	int			i;
	t_champ		*champ;

	champ = vm->champs;
	id_player = 0;
	sit = 0;
	i = 0;
	while (id_player < vm->vs->quantity)
	{
		val = (id_player % 4) + 1;
		i = sit;
		while (i < champ->byte_code->length + sit)
		{
			//printf("%i\n", champ->byte_code->length);
			vm->vs->map[i].id = val;
			i++;
		}
		sit += MEM_SIZE / vm->vs->quantity;
		id_player++;
		champ = champ->next_champ;
	}
}

static void		vs_color_init(void)
{
	start_color();
	init_color(COLOR_MAGENTA, 230, 230, 230);
	init_pair(GREEN_COL, COLOR_GREEN, COLOR_BLACK);
	init_pair(BLUE_COL, COLOR_BLUE, COLOR_BLACK);
	init_pair(YELLOW_COL, COLOR_YELLOW, COLOR_BLACK);
	init_pair(CYAN_COL, COLOR_CYAN, COLOR_BLACK);
	init_pair(RED_COL, COLOR_RED, COLOR_BLACK);
	init_pair(LIVE(YELLOW_COL), COLOR_YELLOW, COLOR_RED);
	init_pair(LIVE(RED_COL), COLOR_RED, COLOR_WHITE);
	init_pair(LIVE(GREEN_COL), COLOR_GREEN, COLOR_WHITE);
	init_pair(LIVE(BLUE_COL), COLOR_BLUE, COLOR_WHITE);
	init_pair(LIVE(CYAN_COL), COLOR_CYAN, COLOR_WHITE);
	init_pair(BORDER, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(EMPTY, COLOR_MAGENTA, COLOR_BLACK);
}

static void		set_view(t_vm *vm)
{
	vm->vs->map_window = newwin(HEIGHT + 3, WIDTH, 1, 2);
	vm->vs->info_window = newwin(HEIGHT + 3, WIDTH / 4 + 3, 1, WIDTH + 6);
	//vm->vs->help_window = newwin(HEIGHT / 5, WIDTH, HEIGHT + 2, 2);
}

static void	init_carriage(t_vm *vm)
{
	t_carriage *current;

	current = vm->cars;
	while (current)
	{
		draw_cursor(vm, current);
		current = current->next;
	}
}

void		config(t_vm *vm)
{
	initscr();
	refresh();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(0);
	cbreak();
	noecho();
	use_default_colors();
	vs_color_init();
	do_map(vm);
	set_view(vm);
	init_carriage(vm);
}
