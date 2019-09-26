/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:57:50 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:57:53 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_command	*add_command_catalog(void)
{
	t_command *tmp;
	t_command *tmp2;

	tmp = (t_command *)malloc(sizeof(t_command));
	*tmp = (t_command){"aff", 16, 4, 2, 0, 1, 1, NULL, NULL};
	tmp2 = (t_command *)malloc(sizeof(t_command));
	*tmp2 = (t_command){"lfork", 15, 2, 1000, 0, 0, 1, NULL, tmp};
	tmp = (t_command *)malloc(sizeof(t_command));
	*tmp = (t_command){"lldi", 14, 2, 50, 1, 1, 3, NULL, tmp2};
	tmp2 = (t_command *)malloc(sizeof(t_command));
	*tmp2 = (t_command){"lld", 13, 4, 10, 1, 1, 2, NULL, tmp};
	tmp = (t_command *)malloc(sizeof(t_command));
	*tmp = (t_command){"fork", 12, 2, 800, 0, 0, 1, NULL, tmp2};
	tmp2 = (t_command *)malloc(sizeof(t_command));
	*tmp2 = (t_command){"sti", 11, 2, 25, 0, 1, 3, NULL, tmp};
	tmp = (t_command *)malloc(sizeof(t_command));
	*tmp = (t_command){"ldi", 10, 2, 25, 0, 1, 3, NULL, tmp2};
	return (tmp);
}

t_command	*get_commad_catalog(void)
{
	t_command *tmp;
	t_command *tmp2;

	tmp = add_command_catalog();
	tmp2 = (t_command *)malloc(sizeof(t_command));
	*tmp2 = (t_command){"zjmp", 9, 2, 20, 0, 0, 1, NULL, tmp};
	tmp = (t_command *)malloc(sizeof(t_command));
	*tmp = (t_command){"xor", 8, 4, 6, 1, 1, 3, NULL, tmp2};
	tmp2 = (t_command *)malloc(sizeof(t_command));
	*tmp2 = (t_command){"or", 7, 4, 6, 1, 1, 3, NULL, tmp};
	tmp = (t_command *)malloc(sizeof(t_command));
	*tmp = (t_command){"and", 6, 4, 6, 1, 1, 3, NULL, tmp2};
	tmp2 = (t_command *)malloc(sizeof(t_command));
	*tmp2 = (t_command){"sub", 5, 4, 10, 1, 1, 3, NULL, tmp};
	tmp = (t_command *)malloc(sizeof(t_command));
	*tmp = (t_command){"add", 4, 4, 10, 1, 1, 3, NULL, tmp2};
	tmp2 = (t_command *)malloc(sizeof(t_command));
	*tmp2 = (t_command){"st", 3, 4, 5, 0, 1, 2, NULL, tmp};
	tmp = (t_command *)malloc(sizeof(t_command));
	*tmp = (t_command){"ld", 2, 4, 5, 1, 1, 2, NULL, tmp2};
	tmp2 = (t_command *)malloc(sizeof(t_command));
	*tmp2 = (t_command){"live", 1, 4, 10, 0, 0, 1, NULL, tmp};
	return (tmp2);
}

t_command	*get_com_byname(t_command *all, char *name)
{
	while (all)
	{
		if (ft_strequ(all->name, name))
			return (all);
		all = all->next;
	}
	return (NULL);
}

char		*find_comm_name(t_command *all, char *name, int n)
{
	while (all)
	{
		if (ft_strnequ(all->name, name, n))
			return (all->name);
		all = all->next;
	}
	return (NULL);
}

void		free_com_catalog(t_command *all)
{
	t_command *tmp;

	while (all)
	{
		tmp = all;
		all = all->next;
		free(tmp);
	}
}
