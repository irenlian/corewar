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

int					get_code_size(char *code);
int valid_magic(char *magic);

#endif
