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

#include "corewar.h"

void	introducing(t_champ *ch)
{
	ft_printf("Introducing contestants...\n");
	while (ch)
	{
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
			ch->id, ch->byte_code->length, ch->header->prog_name, ch->header->comment);
		ch = ch->next_champ;
	}
	
}



void	game(t_vm *vm)
{
	int		res;
	
	while (cycle(vm))
		res = check(vm);
}

int     main(int argc, char **argv)
{
	t_vm	*vm;
    
	vm = create_game();
	vm->champs = get_champs(argc, argv);
	create_arena(vm);
	create_carriages(vm);
	// system("leaks -q corewar");
	introducing(vm->champs);
	game(vm);
    return (0);
}
