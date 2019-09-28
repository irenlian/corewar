#include "corewar.h"
#include "visual.h"

void	live(t_vm *vm, t_carriage *car)
{
	unsigned int	arg_int;
	t_champ			*player;

	// arg_int = (unsigned int)byte_to_int((char*)&vm->arena[to_codage(car)], car->op->dir_size);
	arg_int = (unsigned int)get_arg(vm, car, to_codage(car), 0);
	player = vm->champs;
	while (player)
	{
		if (player->id * -1 == arg_int)
			break ;
		player = player->next_champ;
	}
	if (player)
		vm->last_live = player;
	vm->live_counter++;
	if (vm->vs)
	{
		// update_map(vm, car, 0, 1);
		// vm->vs->map[car->location].cycle_l = CYCLE_WAIT;
		// vm->vs->map[car->location].champ_live = player;
	}
	car->live = 1;
	pass_op(vm, car, NULL);
}

void	load(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			arg_int;

	// arg_sh_int = 0;
	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	(is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND)))))
		return pass_op(vm, car, arg_code);
	// if (get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1 == 3 && car->id == 6)
	// 	arg_sh_int = 0;
	arg_int = get_arg(vm, car, FIRST, ft_strequ(car->op->name, "ld"));
	car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] = arg_int;
	car->carry = (car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] == 0) ? 1 : 0;	
	// if (is_t_ind(arg_code, FIRST))
	// {
	// 	arg_int = get_arg(vm, car, FIRST, ft_strequ(car->op->name, "ld"));
	// 	arg_sh_int = (short)byte_to_int((char*)&vm->arena[arg_index(car, arg_code, FIRST)], IND);
	// 	if (ft_strequ(car->op->name, "ld"))
	// 		arg_sh_int %= IDX_MOD;
	// 	write_int(vm->arena, arg_index(car, arg_code, FIRST), arg_sh_int, IND);
	// 	car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] = arg_int;
	// 	car->carry = (car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] == 0) ? 1 : 0;
	// }
	// else if (is_t_dir(arg_code, FIRST))
	// {
	// 	car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] = read_t_dir(vm->arena, arg_index(car, arg_code, FIRST), car);
	// 	car->carry = (car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] == 0) ? 1 : 0;
	// }
	pass_op(vm, car, arg_code);
}

void	store(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	short			arg_sh_int;
	// int32_t			arg_int;

	// arg_sh_int = 0;
	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) &&
	((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_ind(arg_code, SECOND))))
		return pass_op(vm, car, arg_code);
	if (is_t_ind(arg_code, SECOND))
	{
		arg_sh_int = (short)byte_to_int(vm->arena, arg_index(car, arg_code, SECOND), IND) % IDX_MOD;
		// arg_int = get_arg(vm, car, SECOND, 1);
		write_int(vm->arena, calc_i(car->location + arg_sh_int), car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST)) - 1], DIR);
		if (vm->vs)
			update_map(vm, car, calc_i(car->location + arg_sh_int), car->op->dir_size);
	}
	else if (is_t_reg(arg_code, SECOND))
		car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] = car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST)) - 1];
	pass_op(vm, car, arg_code);
}

void	addition(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST)) &&
		is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND)) &&
		is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD)))
	{
		res = car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST)) - 1] + car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1];
		car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD)) - 1] = res;
		car->carry = (res == 0) ? 1 : 0;
	}
	pass_op(vm, car, arg_code);
}

void	substraction(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST)) &&
		is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND)) &&
		is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD)))
	{
		res = car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST)) - 1] - car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1];
		car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD)) - 1] = res;
		car->carry = (res == 0) ? 1 : 0;
	}
	pass_op(vm, car, arg_code);
}

void	and_or_xor(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	res = 0;
	if (!(((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) || is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_dir(arg_code, SECOND) || is_t_ind(arg_code, SECOND)) &&
	(is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD)))))
		return pass_op(vm, car, arg_code);
	res = get_arg(vm, car, FIRST, 1);
	if (ft_strequ(car->op->name, "and"))
		res = res & get_arg(vm, car, SECOND, 1);
	else if (ft_strequ(car->op->name, "or"))
		res = res | get_arg(vm, car, SECOND, 1);
	else if (ft_strequ(car->op->name, "xor"))
		res = res ^ get_arg(vm, car, SECOND, 1);
	car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD)) - 1] = res;
	car->carry = (res == 0) ? 1 : 0;
	pass_op(vm, car, arg_code);
}

void	zjmp(t_vm *vm, t_carriage *car)
{
	int32_t		arg_int;
	t_champ		*player;

	if (car->carry != 1)
		return pass_op(vm, car, NULL);
	// arg_int = (short)byte_to_int((char*)&vm->arena[to_codage(car)], car->op->dir_size);
	arg_int = get_arg(vm, car, FIRST, 1);
	move_carriage(vm, car, car->location + arg_int % IDX_MOD);
}

void	load_index(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			pos;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	pos = 0;
	if (!(((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) || is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_dir(arg_code, SECOND)) &&
	(is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD)))))
		return pass_op(vm, car, arg_code);
	// if (get_i(vm->arena, arg_index(car, arg_code, THIRD)) - 1 == 3 && car->id == 6)
	// 	pos = 0;
	pos = get_arg(vm, car, FIRST, 1) + get_arg(vm, car, SECOND, 1);
	// pos = (short)byte_to_int((char*)&vm->arena[to_first_arg(car)], car->op->dir_size);
	// pos += (short)byte_to_int((char*)&vm->arena[to_second_arg(car, arg_code)], car->op->dir_size);
	// pos = (short)(get_arg(vm, car, FIRST, arg_code) + get_arg(vm, car, SECOND, arg_code));
	if (ft_strequ(car->op->name, "ldi"))
		pos %= IDX_MOD;
	pos = calc_i(pos + car->location);
	res = (unsigned int)byte_to_int(vm->arena, pos, DIR);
	car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD)) - 1] = res;
	if (ft_strequ(car->op->name, "lldi"))
		car->carry = (res == 0) ? 1 : 0;
	pass_op(vm, car, arg_code);
}

void	store_index(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	short			arg_sh_int;
	int32_t			pos;

	arg_sh_int = 0;
	// if (car->location == 337)
	// 	(1);
	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) &&
	((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_dir(arg_code, SECOND) || is_t_ind(arg_code, SECOND)) &&
	((is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD))) || is_t_dir(arg_code, THIRD))))
		return pass_op(vm, car, arg_code);
	pos = calc_i((get_arg(vm, car, SECOND, 1) + get_arg(vm, car, THIRD, 1)) % IDX_MOD) + car->location;
	write_int(vm->arena, pos, get_arg(vm, car, FIRST, 0), DIR);
	pass_op(vm, car, arg_code);
	if (vm->vs)
		update_map(vm, car, pos, car->op->dir_size);
}

void	lfork(t_vm *vm, t_carriage *car)
{
	int32_t			pos;
	t_carriage		*fork;

	pos = get_arg(vm, car, FIRST, 0);
	// pos = (short)byte_to_int((char*)&vm->arena[to_codage(car)], car->op->dir_size);
	if (ft_strequ(car->op->name, "fork"))
		pos %= IDX_MOD;
	pos += car->location;
	fork = copy_carriage(vm, car);
	fork->location = calc_i(pos);
	// if (fork->id == 231)
	// 	ft_printf("%i\n", fork->live);
	pass_op(vm, car, NULL);
	if (fork->id == 624)
		fork->id = 624;
	// ft_printf("id %i location %i -> id %i location %i\n", car->id, car->location, fork->id, fork->location);
	// fork->op = get_com_by_code(vm->catalog, get_i(vm->arena, fork->location));
}

void	aff(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	int32_t			arg_int;
	char			res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!(is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))))
		return pass_op(vm, car, arg_code);
	arg_int = get_arg(vm, car, FIRST, 0);
	// res = arg_int % 256;
	// write(1, &res, 1);
	ft_printf("Aff: %c\n", (char)arg_int);
	pass_op(vm, car, arg_code);
}
