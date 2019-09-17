#include "corewar.h"

/*
**	Functions return particular command part's index according to carriage location on arena
*/

int		to_codage(t_carriage *car)
{
	int res;

	if (!car)
		return (0);
	res = car->location + OP;
	res %= MEM_SIZE;
	return (res);
}

int		to_first_arg(t_carriage *car)
{
	int res;

	if (!car)
		return (0);
	res = car->location + OP + car->op->codage_octal ? ARG : 0;
	res %= MEM_SIZE;
	return (res);
}

int		to_second_arg(t_carriage *car, char *arg_code)
{
	int res;

	if (!car)
		return (0);
	res = to_first_arg(car);
	if (is_t_reg(arg_code, FIRST))
		res += REG;
	else if (is_t_dir(arg_code, FIRST))
		res += car->op->dir_size;
	else if (is_t_ind(arg_code, FIRST))
		res += IND;
	res %= MEM_SIZE;
	return (res);
}

int		to_third_arg(t_carriage *car, char *arg_code)
{
	int res;

	if (!car)
		return (0);
	res = to_second_arg(car, arg_code);
	if (is_t_reg(arg_code, SECOND))
		res += REG;
	else if (is_t_dir(arg_code, SECOND))
		res += car->op->dir_size;
	else if (is_t_ind(arg_code, SECOND))
		res += IND;
	res %= MEM_SIZE;
	return (res);
}

int		arg_index(t_carriage *car, char *arg_code, int arg_pos)
{
	if (arg_pos == FIRST)
		return (to_first_arg(car));
	else if (arg_pos == SECOND)
		return (to_second_arg(car, arg_code));
	else if (arg_pos == THIRD)
		return (to_third_arg(car, arg_code));
	else
		return (0);
}