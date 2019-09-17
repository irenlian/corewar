#include "corewar.h"

void	live(t_vm *vm, t_carriage *car)
{
	unsigned int	arg_int;
	t_champ			*player;

	arg_int = read_t_dir(vm->arena, to_codage(car));
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
	arg_code = get_bits(get_i(vm->arena, to_codage(car->location)));
	if (is_t_reg(arg_code, SECOND) && ((is_t_ind(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, SECOND)) ||
		(is_t_dir(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))))))
	{
		if (is_t_ind(arg_code, FIRST))
		{
			arg_sh_int = read_t_ind(vm->arena, arg_index(car, arg_code, FIRST));
			write_t_ind(vm->arena, arg_index(car, arg_code, FIRST), arg_sh_int);
			car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND))] = read_t_dir(vm->arena, calc_i(car->location + arg_sh_int));
			car->carry = (car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND))] == 0) ? 1 : 0;
		}
		else if (is_t_dir(arg_code, FIRST))
		{
			car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND))] = read_t_dir(vm->arena, arg_index(car, arg_code, FIRST));
			car->carry = (car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND))] == 0) ? 1 : 0;
		}
		else
			invalid_op(car, arg_code);
	}
	else
		invalid_op(car, arg_code);
}

void	store(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	short			arg_sh_int;

	arg_sh_int = 0;
	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	if (is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST)))
	{
		if (is_t_ind(arg_code, SECOND))
		{
			arg_sh_int = read_t_ind(vm->arena, arg_index(car, arg_code, SECOND));
			vm->arena[calc_i(car->location + arg_sh_int)] = car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST))];
		}
		else if (is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND)))
		{
			car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND))] = car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST))];
		}
		else
			invalid_op(car, arg_code);
	}
	else
		invalid_op(car, arg_code);
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
		res = car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST))] + car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND))];
		car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD))] = res;
		car->carry = (res == 0) ? 1 : 0;
	}
	else
		invalid_op(car, arg_code);
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
		res = car->registers[get_i(vm->arena, arg_index(car, arg_code, FIRST))] - car->registers[get_i(vm->arena, arg_index(car, arg_code, SECOND))];
		car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD))] = res;
		car->carry = (res == 0) ? 1 : 0;
	}
	else
		invalid_op(car, arg_code);
}

unsigned int	get_arg(t_vm *vm, t_carriage *car, int arg_i, char *arg_code)
{
	short			arg_sh_int;

	if (is_t_reg(arg_code, arg_i) && is_valid_reg(vm, arg_index(car, arg_code, arg_i)))
		return (car->registers[get_i(vm->arena, arg_index(car, arg_code, arg_i))]);
	else if (is_t_dir(arg_code, arg_i))
		return (read_t_dir(vm->arena, arg_index(car, arg_code, arg_i)));
	else if (is_t_ind(arg_code, arg_i))
	{
		arg_sh_int = read_t_ind(vm->arena, arg_index(car, arg_code, arg_i));
		return (read_t_dir(vm->arena, calc_i(car->location + arg_sh_int)));
	}
	else
		return (0);
}

void	and_or_xor(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	res = 0;
	if (!((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) || is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	!((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_dir(arg_code, SECOND) || is_t_ind(arg_code, SECOND)) &&
	!(is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD))))
	{
		invalid_op(car, arg_code);
		return ;
	}
	res = get_arg(vm, car, FIRST, arg_code);
	if (ft_strequ(car->op->name, "and"))
		res = res & get_arg(vm, car, SECOND, arg_code);
	else if (ft_strequ(car->op->name, "or"))
		res = res | get_arg(vm, car, SECOND, arg_code);
	else if (ft_strequ(car->op->name, "xor"))
		res = res ^ get_arg(vm, car, SECOND, arg_code);
	car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD))] = res;
}

void	zjmp(t_vm *vm, t_carriage *car)
{
	unsigned int	arg_int;
	t_champ			*player;

	if (car->carry != 1)
		return ;
	arg_int = read_t_dir(vm->arena, to_codage(car));
	car->location = calc_i(car->location + arg_int % IDX_MOD);
}

void	load_index(t_vm *vm, t_carriage *car)
{
	char			*arg_code;
	unsigned int	pos;
	unsigned int	res;

	arg_code = get_bits(get_i(vm->arena, to_codage(car)));
	pos = 0;
	if (!((is_t_reg(arg_code, FIRST) && is_valid_reg(vm, arg_index(car, arg_code, FIRST))) || is_t_dir(arg_code, FIRST) || is_t_ind(arg_code, FIRST)) &&
	!((is_t_reg(arg_code, SECOND) && is_valid_reg(vm, arg_index(car, arg_code, SECOND))) || is_t_dir(arg_code, SECOND)) &&
	!(is_t_reg(arg_code, THIRD) && is_valid_reg(vm, arg_index(car, arg_code, THIRD))))
	{
		invalid_op(car, arg_code);
		return ;
	}
	pos = ((get_arg(vm, car, FIRST, arg_code) + get_arg(vm, car, SECOND, arg_code)) % IDX_MOD) + car->location;
	res = read_t_dir(vm->arena, pos);
	car->registers[get_i(vm->arena, arg_index(car, arg_code, THIRD))] = res;
}