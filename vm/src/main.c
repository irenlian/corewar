/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:13:59 by pdemian           #+#    #+#             */
/*   Updated: 2019/09/11 19:14:00 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int     main(int argc, char **argv)
{
	t_vm	*vm;
    
	vm = create_game();
	vm->champs = get_champs(argc, argv);
    return (0);
}
