/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 13:03:30 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/12 13:04:40 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H

# define VISUAL_H

# include "../libft/includes/libft.h"
# include "op.h"
# include "corewar.h"
# include <ncurses.h>
# include <curses.h>
# include <stdint.h>
# include <unistd.h>
# include <string.h>

# define ONE 1

# define GREEN_COL 3
# define BLUE_COL 4
# define YELLOW_COL 1
# define CYAN_COL 5
# define RED_COL 2
# define GREY 12

# define BORDER 9
# define EMPTY 12

# define LIVE(x) (x + 5)
# define MODULO(x) (((x) % 4) + 1)
# define PAIR(x) (COLOR_PAIR (MODULO(x)))

# define MIN_PL 1
# define MAX_PL 4
# define BYTE_PER_LINE 64

# define HEIGHT					(MEM_SIZE / 64)
# define WIDTH					(64 * 3 + 5)
# define INDENT					5
# define INDENT_ONE				1
# define INDENT_CENTER			12
# define INDENT_THREE			8
# define TAB_LEN				4

# define HELP 'h'
# define MUSIC 'm'
# define SPACE ' '

# define MICROSEC 1000000

# define CARRIAGE_NUM(X)		((X) + 5)
# define CYCLE_LIMIT			50
# define CYCLE_WAIT				50

typedef struct		s_moves
{
	int				id;
	size_t			cycle_s;
	size_t			cycle_l;
	t_champ			*champ_live;
}					t_moves;

typedef struct		s_window
{
	WINDOW			*win;
	int				w;
	int				h;
	int				x;
	int				y;
}					t_win;

typedef struct		s_vs
{
	t_bool			is_run;
	int				speed;
	WINDOW			*map_window;
	WINDOW			*info_window;
	WINDOW			*help_window;
	int				pixels;
	t_moves			map[MEM_SIZE];
	int				button;
	unsigned		microsec;
	t_champ			*aff;
	t_bool			sounds;
	t_bool			winner;
	int				quantity;
	int				carriages_num;
}					t_vs;

/*
** Main functions
*/

void				vs_broach(t_vm *vm);
void				config(t_vm *vm);
void				button(t_vm *vm);
int					calc_addr(int addr);
t_vs				*init_visual(void);

/*
** Sounds
*/

void				voice_of_game(t_vm *vm);
void				voice_of_victory(t_vm *vm);

/*
** Windows
*/

void				make_map(t_vm *vm);
void				draw_info_win(t_vm *vm);
void				draw_help_win(t_vm *vm);
void				make_info_window(t_vm *vm);

/*
** Information
*/

void				show_pause_win(t_vm *vm);
void				show_end_win(t_vm *vm);
void				show_fighting_win(t_vm *vm);
void				show_players_win(t_vm *vm);
void				draw_winner(t_vm *vm, int index);
void				draw_vs(t_vm *vm);
void				show_run_status(t_vm *vm);
void				show_authors(t_vm *vm);
void				show_params(t_vm *vm);
void				show_champs(t_vm *vm);
void				show_help(t_vm *vm);

#endif
