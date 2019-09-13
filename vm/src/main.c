/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:46:39 by ilian             #+#    #+#             */
/*   Updated: 2019/09/13 13:46:41 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/corewar.h"

int     main(int argc, char **argv)
{
	t_vm	*vm;
    
	vm = create_game();
	vm->champs = get_champs(argc, argv);
	create_arena(vm);
	create_carriages(vm);
	// system("leaks -q corewar");
    return (0);
}
