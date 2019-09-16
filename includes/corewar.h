/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:54:30 by pdemian           #+#    #+#             */
/*   Updated: 2019/09/11 15:54:32 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdlib.h>
# include <fcntl.h>
# include "op.h"

# include "../libft/includes/libft.h"

# define MAX_FILE_LENGTH		(CHAMP_MAX_SIZE + PROG_NAME_LENGTH + COMMENT_LENGTH + 4 * 8)


typedef struct		s_byte_code
{
    int				length;
    char			*code;
}					t_byte_code;

typedef struct		s_champ
{
    int				id;
	t_header		*header;
    t_byte_code		*byte_code;
	t_list			*asm_code;
    struct s_champ	*next_champ;
}					t_champ;

typedef struct		s_carriage
{
    int				id;
	int				location;
	int				carry;
	unsigned int	registers[REG_NUMBER];
	int				live;
	void			(*func)();
	int				cycles_to_run;
	struct s_carriage	*next;
}					t_carriage;

/*
**	VM - is a basic structure with main variables to hold the game
**
**	cycles_to_die - number of cycles that should past till check and is decreasing during game
**	cycles_till_next_check - number of cycles that should past till next check
**	cycles_counter - number of cycles from the beginning
**	live_counter - number of live command from all carriages from last check
**	check_counter - number of checks from the last decreasing of cycles_to_die
**	checks_from_start - number of checks from the beginning
*/

typedef struct		s_vm
{
    t_champ			*champs;
	char			*arena;
	t_carriage			*cars;
	t_champ			*last_live;
	int				cycles_to_die;
	int				cycles_till_next_check;
	int				cycles_counter;
	int				live_counter;
	int				check_counter;
	int				checks_from_start;
}					t_vm;

typedef struct		s_command
{
    char            *name;
    int             code;
    int             dir_size;
    int             cycles;
    int             carry;
    int             codage_octal;
    struct s_command    *next;
}					t_command;

typedef struct		s_code
{
    int             id; //порядковый номер
    int             byte_size; // размер кода в байтах (Дем*яну не заполнять)
    char            *mark;
    char            *name;
    char            *arg1;
    char            *arg2;
    char            *arg3;
    struct s_code   *next;
}					t_code;
/*
**	VM functions
*/

t_vm				*create_game();
void				create_arena(t_vm *vm);
t_champ 			*create_champ(t_byte_code *str_champ, int id);
void				create_carriages(t_vm *vm);
t_champ				*get_champs(int argc, char **argv);
int					get_quantity_players(t_champ *champ);
int					byte_to_int(char *str);
int					check(t_vm *vm);
int					cycle(t_vm *vm);

/*
**	Assembler functions
*/

int				show_error(const char *error);
int				read_code(t_champ *champ, char *f_name);
t_command       *get_commad_catalog();
t_command       *get_com_byname(t_command *all, char *name);
void            free_com_catalog(t_command *all);
int             valid_champ_name(char *name);
void            set_int(int fd, int code, int bytes);
void            set_name(int fd, char *name, int max_length);
t_code          *get_code_by_mark(t_code  *code, char *mark);
void            write_exec_code(int fd, t_code *code, t_command *catalog);
int             get_int_from_bytes(char *byte_code);

#endif
