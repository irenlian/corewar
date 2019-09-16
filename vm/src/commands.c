#include "corewar.h"

void	live(t_vm *vm, t_carriage *car)
{
	unsigned int	arg_int;
	t_champ			*player;

	arg_int = read_t_dir(vm->arena, car->location + 1);
	player = vm->champs;
	while (player)
	{
		if (player->id == arg_int)
			break ;
		player = player->next_champ;
	}
	if (player)
		vm->last_live = player;
	vm->live_counter++;
	car->live = 1;
}

void	store(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	short			arg_sh_int;

	arg_sh_int = 0;
	arg_code = get_bits(get_i(vm->arena, car->location + 1));
	if (is_t_ind(arg_code, 2))
	{
		arg_sh_int = read_t_ind(vm->arena, car->location + 3);
		vm->arena[calc_i(car->location + arg_sh_int)] = car->registers[get_i(vm->arena, car->location + 2)];
	}
	else if (is_t_reg(arg_code, 2) && get_i(vm->arena, car->location + 3) < REG_NUMBER)
	{
		car->registers[get_i(vm->arena, car->location + 3)] = car->registers[get_i(vm->arena, car->location + 2)];
	}
	else
	{
		car->location = calc_i(car->location + 2 + calc_args_length(arg_code, car->op->args_num, car->op->dir_size));
	}
}