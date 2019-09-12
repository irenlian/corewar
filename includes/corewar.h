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

typedef struct		s_champ
{
    int				id;
	t_header		*header;
    char			*code;
    struct s_champ	*next_champ;
}					t_champ;

typedef struct		s_carriage
{
    int				id;
	int				location;
	int				carry;
	unsigned int	registers[16];
	int				live;
	void			(*func)();
	int				cycles_to_run;
}					t_carriage;

typedef struct		s_vm
{
    t_champ			*champs;
	char			*arena;
	t_champ			*last_live;
	int				cycles_to_die;
	int				cycles_counter;
	int				live_counter;
	int				check_counter;
}					t_vm;

typedef struct		s_byte_code
{
    int				length;
    char			*code;
}					t_byte_code;

t_vm				*create_game();
t_champ				*get_champs(int argc, char **argv);
int					get_quantity_players(t_champ *champ);
int					byte_to_int(char *str);

#endif
