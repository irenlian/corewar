/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:46:39 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:54:40 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "visual.h"

void	introducing(t_champ *ch)
{
	ft_printf("Introducing contestants...\n");
	while (ch)
	{
		ft_printf("* Player %i, weighing %i bytes, \"%s\" (\"%s\") !\n",
			ch->id, ch->byte_code->length,
			ch->header->prog_name, ch->header->comment);
		ch = ch->next_champ;
	}
}

void	winner(t_vm *vm)
{
	if (vm->last_live)
		ft_printf("Contestant %i, \"%s\", has won !\n",
		vm->last_live->id, &(vm->last_live->header->prog_name[0]));
	else
		ft_printf("There is no winner.\n");
}

void	game(t_vm *vm)
{
	int		res;

	res = 1;
	if (vm->vs)
		vs_broach(vm);
	else
	{
		introducing(vm->champs);
		if (vm->cycles_counter == vm->dump)
			print_arena(vm);
		while (cycle(vm) && res && vm->cycles_counter != vm->dump)
		{
			res = check(vm);
		}
		if (vm->cycles_counter == vm->dump)
			print_arena(vm);
		winner(vm);
	}
}

int		main(int argc, char **argv)
{
	t_vm	*vm;
	t_champ	*last;
	int		i;

	vm = create_game();
	read_arguments(vm, argc, argv);
	if (!vm->champs)
		show_error_vm(NULL, vm, 1);
	normalize_id(vm->champs);
	last = vm->champs;
	while (last->next_champ)
		last = last->next_champ;
	vm->last_live = last;
	create_arena(vm);
	create_carriages(vm);
	game(vm);
	if (vm->leaks)
		system("leaks -q corewar");
	return (0);
}
