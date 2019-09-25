/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:46:07 by ilian             #+#    #+#             */
/*   Updated: 2019/09/13 13:46:09 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_byte_code   *read_file(char *path)
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
	{
		free(bytes);
		show_error_vm(ft_strjoin("Can't read source file ", path), NULL);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_memcpy(tmp, buf, ret);
		bytes->length += ret;
		tmp += ret;
	}
	if (ret == -1)
	{
		free(bytes);
		show_error_vm(ft_strjoin("Can't read source file ", path), NULL);
	}
	close(fd);
    return (bytes);
}

void	normalize_id(t_champ *champ)
{
	int		i;

	i = 1;
	while (champ)
	{
		champ->id = i++;;
		champ = champ->next_champ;
	}
}

int		insert_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*tmp;
	t_champ	*prev;
	int		i;

	tmp = vm->champs;
	prev = NULL;
	i = 0;
	while (tmp)
	{
		if (tmp->id >= champ->id)
		{
			champ->next_champ = tmp;
			if (prev)
				prev->next_champ = champ;
			else
				vm->champs = champ;
			if (tmp->id == champ->id)
				normalize_id(vm->champs);
			return (1);
		}
		prev = tmp;
		tmp = tmp->next_champ;
	}
	return (0);
}

int		push_champ(t_vm *vm, t_champ *champ)
{
	t_champ	*tmp;

	tmp = vm->champs;
	while (tmp->next_champ)
		tmp = tmp->next_champ;
	tmp->next_champ = champ;
	return (1);
}

int		autoincrement_id(int *order, t_champ *champ)
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

void	read_arguments(t_vm *vm, int argc, char **argv)
{
    t_champ	*tmp;
	int		order;
    int 	i;

    i = 0;
	order = 0;
    while (++i < argc)
    {
		if (ft_strequ(argv[i], "-v") && !vm->vs)
			vm->vs = init_visual();
		else if (ft_strequ(argv[i], "-l"))
			vm->leaks = 1;
		else if (ft_strequ(argv[i], "-dump"))
			vm->dump = ft_atoi(argv[++i]);
		else if (ft_strequ(argv[i], "-n"))
		{
			order = ft_atoi(argv[++i]);
			if (!is_str_digits(argv[i]) || order < 1 || order > MAX_PLAYERS)
				show_error_vm("Usage of flag [[-n number] player_name]\n\"number\" is from 1 to maximum players quantity\n", vm);
		}
		else if (vm->champs)
		{
			tmp = create_champ(read_file(argv[i]), autoincrement_id(&order, vm->champs));
			if (tmp)
				insert_champ(vm, tmp) || push_champ(vm, tmp);
		}
		else
			vm->champs = create_champ(read_file(argv[i]), autoincrement_id(&order, vm->champs));
		
    }
	normalize_id(vm->champs);
}
