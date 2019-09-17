#include "corewar.h"

unsigned int	read_t_dir(char *arena, int arg_location)
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

short		read_t_ind(char *arena, int arg_location)
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
	res = *num % IDX_MOD;
	free(num);
	return (res);
}

void		write_t_ind(char *arena, int arg_location, short value)
{
	arena[arg_location] = value >> (8);
	arena[++arg_location] = value;
}