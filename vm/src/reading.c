/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:46:07 by ilian             #+#    #+#             */
/*   Updated: 2019/09/28 16:55:11 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			file_error(t_byte_code *bytes, char *path)
{
	free(bytes);
	show_error_vm(path, NULL, 2);
}

t_byte_code		*rdf(char *path)
{
	t_byte_code	*bytes;
	int			fd;
	char		buf[BUFF_SIZE];
	int			ret;
	char		*tmp;

	bytes = (t_byte_code*)ft_memalloc(sizeof(t_byte_code));
	*bytes = (t_byte_code){0, ft_strnew(MAX_FILE_LENGTH)};
	tmp = bytes->code;
	if ((fd = open(path, O_RDONLY)) == -1)
		file_error(bytes, path);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_memcpy(tmp, buf, ret);
		bytes->length += ret;
		tmp += ret;
	}
	if (ret == -1)
		file_error(bytes, path);
	close(fd);
	return (bytes);
}

int				inc_id(int *order, t_champ *champ)
{
	int		res;

	res = 0;
	if (*order)
	{
		res = *order;
		*order = 0;
		return (res);
	}
	while (champ)
	{
		if (champ->id - res > 1)
			return (++res);
		res = champ->id;
		champ = champ->next_champ;
	}
	return (++res);
}

int				set_flags(t_vm *vm, char **argv, int *index)
{
	int i;

	i = *index;
	if (ft_strequ(argv[i], "-v") && !vm->vs)
	{
		vm->vs = init_visual();
		return (1);
	}
	else if (ft_strequ(argv[i], "-l"))
	{
		vm->leaks = 1;
		return (1);
	}
	else if (ft_strequ(argv[i], "-dump"))
	{
		vm->dump = ft_atoi(argv[++*index]);
		return (1);
	}
	return (0);
}

void			read_arguments(t_vm *vm, int argc, char **argv)
{
	t_champ	*tmp;
	int		order;
	int		i;

	i = 0;
	order = 0;
	while (++i < argc)
	{
		if (set_flags(vm, argv, &i))
			;
		else if (ft_strequ(argv[i], "-n"))
		{
			order = ft_atoi(argv[++i]);
			if (!is_str_digits(argv[i]) || order < 1 || order > MAX_PLAYERS)
				show_error_vm(NULL, vm, 1);
		}
		else if (vm->champs)
		{
			tmp = create_champ(rdf(argv[i]), inc_id(&order, vm->champs));
			if (tmp)
				insert_champ(vm, tmp) || push_champ(vm, tmp);
		}
		else
			vm->champs = create_champ(rdf(argv[i]), inc_id(&order, vm->champs));
	}
}
