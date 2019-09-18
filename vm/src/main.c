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
	
	res = 1;
	while (cycle(vm) && res)
		res = check(vm);
}

void	winner(t_vm *vm)
{
	int		i;

	if (vm->last_live)
	{
		i = 0;
		ft_printf("Winner iiisss ...\n");
		while (i++ < 15)
			ft_printf("...\n");
		ft_printf("%s\n", &(vm->last_live->header->prog_name[0]));
	}
	else
		ft_printf("There is no winner.\n");
}

int     main(int argc, char **argv)
{
	t_vm	*vm;
	int		i;
    
	vm = create_game();
	vm->champs = get_champs(argc, argv);
	create_arena(vm);
	create_carriages(vm);
	// system("leaks -q corewar");
	introducing(vm->champs);
	game(vm);
	winner(vm);
    return (0);
}
