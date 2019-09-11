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
# include "./op.h"

# include "../libft/includes/libft.h"

typedef struct l_champ
{
    int              id;
    char            *name;
    char            *coment;
    int             *champ_size;
    char            *code;
    struct l_champ  *next_champ;
}                   t_champ;

typedef struct l_str
{
    char            *line;
    struct l_str    *next;
}                   t_str;

t_str   *create_tstr(char *str);
t_champ   *create_lchamp();

#endif
