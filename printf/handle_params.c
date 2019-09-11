/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:50:44 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 11:50:47 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			put_precision(t_params *list, char *fmt)
{
	int i;

	i = 1;
	while (fmt[i] >= '0' && fmt[i] <= '9')
	{
		list->precision = (list->precision == -1) ?
		fmt[i] - 48 : list->precision * 10 + (fmt[i] - 48);
		i++;
	}
	if (list->precision == -1)
		list->precision = 0;
	return (i - 1);
}

int			put_width(t_params *list, char *fmt)
{
	int i;

	i = 0;
	while (fmt[i] >= '0' && fmt[i] <= '9')
	{
		list->min_width = (list->min_width == 0) ?
		fmt[i] - 48 : list->min_width * 10 + (fmt[i] - 48);
		i++;
	}
	return (i - 1);
}

t_params	*get_params(char *fmt, int i)
{
	t_params	*list;

	list = create_list(i++);
	while (fmt[i] != '\0' &&
		(ft_strchr("#+0- 123456789.lhLscpdiouxXf%", fmt[i])))
	{
		if (ft_strchr("#+0- ", fmt[i]))
			put_flag(list->flags, fmt[i]);
		else if (ft_strchr("lhL", fmt[i]))
			put_modify(list->modify, fmt[i]);
		else if (ft_strchr("123456789", fmt[i]))
			i = put_width(list, &fmt[i]) + i;
		else if (ft_strchr(".", fmt[i]))
			i = put_precision(list, &fmt[i]) + i;
		else if (ft_strchr("scpdiouxXf%", fmt[i]))
		{
			list->type = fmt[i++];
			break ;
		}
		i++;
	}
	list->last_index = i - 1;
	return (list);
}

void		put_flag(char *container, char flag)
{
	if (flag == '0')
		container[0] = flag;
	else if (flag == '#')
		container[1] = flag;
	else if (flag == '-')
		container[2] = flag;
	else if (flag == '+')
		container[3] = flag;
	else if (flag == ' ')
		container[4] = flag;
}

void		put_modify(char *container, char mode)
{
	int	i;

	i = 0;
	if (container[0] == '\0')
		container[0] = mode;
	else if (container[0] == mode)
		container[1] = mode;
	else
	{
		container[0] = mode;
		container[1] = '\0';
	}
}
