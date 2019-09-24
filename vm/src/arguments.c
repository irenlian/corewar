#include "corewar.h"

unsigned int	read_u_int(unsigned char *arena, int arg_location, t_carriage *car)
{
	char			*tmp;
	unsigned int	*num;
	unsigned int	res;

	tmp = ft_strnew(sizeof(unsigned int));
	tmp[0] = get_i(arena, arg_location + 3);
	tmp[1] = get_i(arena, arg_location + 2);
	tmp[2] = get_i(arena, arg_location + 1);
	tmp[3] = get_i(arena, arg_location + 0);
	num = (unsigned int*)ft_memalloc(sizeof(unsigned int));
	ft_memcpy(num, tmp, sizeof(unsigned int));
	free(tmp);
	res = *num;
	free(num);
	return (res);
}

long			read_t_dir(unsigned char *arena, int arg_location, t_carriage *car)
{
	if (car->op->dir_size == IND)
		return (read_clean_t_ind(arena, arg_location));
	else if (car->op->dir_size == DIR)
		return (read_u_int(arena, arg_location, car));
	else
		return (0);
}

short		read_clean_t_ind(unsigned char *arena, int arg_location)
{
	char	*tmp;
	short	*num;
	short	res;

	tmp = ft_strnew(sizeof(short) - 1);
	tmp[0] = get_i(arena, arg_location + 1);
	tmp[1] = get_i(arena, arg_location);
	num = (short*)ft_memalloc(sizeof(short));
	ft_memcpy(num, tmp, sizeof(short));
	free(tmp);
	res = *num;
	free(num);
	return (res);
}

short		read_t_ind(unsigned char *arena, int arg_location)
{
	return (read_clean_t_ind(arena, arg_location) % IDX_MOD);
}

void		write_t_ind(unsigned char *arena, unsigned int arg_location, short value)
{
	arg_location %= MEM_SIZE;
	arena[arg_location++] = value >> (8);
	arg_location %= MEM_SIZE;
	arena[arg_location] = value;
}

void		write_t_dir(unsigned char *arena, unsigned int arg_location, unsigned int value)
{
	arg_location %= MEM_SIZE;
	arena[arg_location++] = value >> (3 * 8);
	arg_location %= MEM_SIZE;
	arena[arg_location++] = value >> (2 * 8);
	arg_location %= MEM_SIZE;
	arena[arg_location++] = value >> (8);
	arg_location %= MEM_SIZE;
	arena[arg_location] = value;
}

long		get_arg(t_vm *vm, t_carriage *car, int arg_i, char *arg_code)
{
	short			arg_sh_int;

	if (is_t_reg(arg_code, arg_i) && is_valid_reg(vm, arg_index(car, arg_code, arg_i)))
		return (car->registers[get_i(vm->arena, arg_index(car, arg_code, arg_i)) - 1]);
	else if (is_t_dir(arg_code, arg_i))
		return (read_t_dir(vm->arena, arg_index(car, arg_code, arg_i), car));
	else if (is_t_ind(arg_code, arg_i))
	{
		arg_sh_int = read_t_ind(vm->arena, arg_index(car, arg_code, arg_i));
		return (read_t_dir(vm->arena, calc_i(car->location + arg_sh_int), car));
	}
	else
		return (0);
}