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
#define OP						1
#define ARG						1
#define REG						1
#define IND						2
#define DIR						4

#define FIRST					1
#define SECOND					2
#define THIRD					3

struct		s_byte_code;
struct		s_champ;
struct		s_command;
struct		s_carriage;
struct		s_vm;

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

typedef struct		s_command
{
    char            *name;
    int             code;
    int             dir_size;
    int             cycles;
    int             carry;
    int             codage_octal;
    int             args_num;
	void			(*func)(struct s_vm *, struct s_carriage *);
    struct s_command    *next;
}					t_command;

typedef struct		s_carriage
{
    int				id;
	unsigned int	location;
	int				carry;
	unsigned int	registers[REG_NUMBER];
	int				live;
	t_command		*op;
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
	t_command		*catalog;
}					t_vm;

typedef struct		s_code
{
    int             id; //порядковый номер
    int             byte_size; // размер кода в байтах (Дем*яну не заполнять)
    t_list          *mark;
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
char				*get_bits(unsigned char octet);
char				get_i(char *arena, int i);
int					calc_i(int i);
unsigned int		read_t_dir(char *arena, int arg_location, t_carriage *car);
short				read_t_ind(char *arena, int arg_location);
short				read_clean_t_ind(char *arena, int arg_location);
void				write_t_ind(char *arena, unsigned int arg_location, short value);
void				write_t_dir(char *arena, unsigned int arg_location, unsigned int value);
int					is_t_dir(char *arg_code, int arg_pos);
int					is_t_ind(char *arg_code, int arg_pos);
int					is_t_reg(char *arg_code, int arg_pos);
unsigned int		get_arg(t_vm *vm, t_carriage *car, int arg_i, char *arg_code);
int					calc_args_length(char *arg_code, unsigned int num, int dir_size);
void				pass_op(t_vm *vm, t_carriage *car);
int					is_valid_reg(t_vm *vm, int loc);
t_carriage			*copy_carriage(t_vm *vm, t_carriage *car);
int					calc_carriages(t_vm *vm);

void				live(t_vm *vm, t_carriage *car);
void				load(t_vm *vm, t_carriage *car);
void				store(t_vm *vm, t_carriage *car);
void				addition(t_vm *vm, t_carriage *car);
void				substraction(t_vm *vm, t_carriage *car);
void				and_or_xor(t_vm *vm, t_carriage *car);
void				zjmp(t_vm *vm, t_carriage *car);
void				load_index(t_vm *vm, t_carriage *car);
void				store_index(t_vm *vm, t_carriage *car);
void				lfork(t_vm *vm, t_carriage *car);
void				aff(t_vm *vm, t_carriage *car);

int					to_codage(t_carriage *car);
int					to_first_arg(t_carriage *car);
int					to_second_arg(t_carriage *car, char *arg_code);
int					to_third_arg(t_carriage *car, char *arg_code);
int					arg_index(t_carriage *car, char *arg_code, int arg_pos);

/*
**	Assembler functions
*/

int				show_error(const char *error);
int				read_code(t_champ *champ, char *f_name);
t_command       *get_commad_catalog();
t_command       *get_com_byname(t_command *all, char *name);
t_command 		*get_com_by_code(t_command *all, char code);
void            free_com_catalog(t_command *all);
int             valid_champ_name(char *name);
void            set_int(int fd, int code, int bytes);
void            set_name(int fd, char *name, int max_length);
t_list          *get_code_by_mark(t_list  *code_list, char *mark);
void            write_exec_code(int fd, t_list *code_list, t_command *catalog);
int             get_int_from_bytes(char *byte_code);
void            valid_operation(char *line);
void            valid_champ_file(t_list *champ);

#endif
