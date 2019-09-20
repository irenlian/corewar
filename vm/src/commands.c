#include "corewar.h"

void	live(t_vm *vm, t_carriage *car)
{
	unsigned int	arg_int;
	t_champ			*player;

	arg_int = read_t_dir(vm->arena, to_codage(car), car);
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

void	load(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	short			arg_sh_int;

	arg_sh_int = 0;
	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	(is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND)))))
		return ;
	if (is_t_ind(arg_code, FIRST))
	{
		arg_sh_int = ft_strequ(car->op->name, "lld") ? read_clean_t_ind(vm->arena, arg_index(car, arg_code, FIRST)) : read_t_ind(vm->arena, arg_index(car, arg_code, FIRST));
		write_t_ind(vm->arena, arg_index(car, arg_code, FIRST), arg_sh_int);
		car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] = read_t_dir(vm->arena, calc_i(car->location + arg_sh_int), car);
		car->carry = (car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] == 0) ? 1 : 0;
	}
	else if (is_t_dir(arg_code, FIRST))
	{
		car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] = read_t_dir(vm->arena, arg_index(car, arg_code, FIRST), car);
		car->carry = (car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] == 0) ? 1 : 0;
	}
}

void	store(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	short			arg_sh_int;

	arg_sh_int = 0;
	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) &&
	((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_ind(arg_code, SECOND))))
		return ;
	if (is_t_ind(arg_code, SECOND))
	{
		arg_sh_int = read_t_ind(vm->arena, arg_index(car, arg_code, SECOND));
		write_t_dir(vm->arena, calc_i(car->location + arg_sh_int), car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST)) - 1]);
	}
	else if (is_t_reg(arg_code, SECOND))
		car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND)) - 1] = car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST)) - 1];
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
}

void	and_or_xor(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	res = 0;
	if (!(((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) || is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_dir(arg_code, SECOND) || is_t_ind(arg_code, SECOND)) &&
	(is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD)))))
		return ;
	res = get_arg(vm, car, FIRST, arg_code);
	if (ft_strequ(car->op->name, "and"))
		res = res & get_arg(vm, car, SECOND, arg_code);
	else if (ft_strequ(car->op->name, "or"))
		res = res | get_arg(vm, car, SECOND, arg_code);
	else if (ft_strequ(car->op->name, "xor"))
		res = res ^ get_arg(vm, car, SECOND, arg_code);
	car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD)) - 1] = res;
}

void	zjmp(t_vm *vm, t_carriage *car)
{
	short		arg_int;
	t_champ		*player;

	if (car->carry != 1)
		return ;
	arg_int = read_t_dir(vm->arena, to_codage(car), car);
	car->location = calc_i(car->location + arg_int % IDX_MOD);
}

void	load_index(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	long			pos;
	short			res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	pos = 0;
	if (!(((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) || is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_dir(arg_code, SECOND)) &&
	(is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD)))))
		return ;
	pos = get_arg(vm, car, FIRST, arg_code) + get_arg(vm, car, SECOND, arg_code);
	if (ft_strequ(car->op->name, "ldi"))
		pos %= IDX_MOD;
	pos = calc_i(pos + car->location);
	res = read_t_dir(vm->arena, pos, car);
	car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD)) - 1] = res;
	if (ft_strequ(car->op->name, "lldi"))
		car->carry = (res == 0) ? 1 : 0;
}

void	store_index(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	short			arg_sh_int;
	unsigned int	pos;

	arg_sh_int = 0;
	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) &&
	((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_dir(arg_code, SECOND) || is_t_ind(arg_code, SECOND)) &&
	((is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD))) || is_t_dir(arg_code, THIRD))))
		return ;
	pos = calc_i(((get_arg(vm, car, SECOND, arg_code) + get_arg(vm, car, THIRD, arg_code)) % IDX_MOD) + car->location);
	write_t_dir(vm->arena, pos, get_arg(vm, car, FIRST, arg_code));
}

void	lfork(t_vm *vm, t_carriage *car)
{
	int				pos;
	t_carriage		*fork;

	pos = read_t_dir(vm->arena, to_codage(car), car);
	if (ft_strequ(car->op->name, "fork"))
		pos %= IDX_MOD;
	pos += car->location;
	fork = copy_carriage(vm, car);
	fork->location = calc_i(pos);
	// fork->op = get_com_by_code(vm->catalog, get_i(vm->arena, fork->location));
}

void	aff(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	unsigned int	arg_int;
	char			res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (!(is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))))
		return ;
	arg_int = get_arg(vm, car, FIRST, arg_code);
	res = arg_int % 256;
	write(1, &res, 1);
}
