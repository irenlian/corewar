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

typedef struct		s_vm
{
    t_champ			*champs;
	char			*arena;
	t_carriage			*cars;
	t_champ			*last_live;
	int				cycles_to_die;
	int				cycles_counter;
	int				live_counter;
	int				check_counter;
}					t_vm;

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

/*
**	Assembler functions
*/

int				show_error(const char *error);
int				read_code(t_champ *champ, char *f_name);


#endif
