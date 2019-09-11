/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:33:51 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 11:33:55 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *fmt, ...)
{
	t_params	*list;
	int			len;
	va_list		ap;

	list = fill_params(fmt);
	validate(list);
	va_start(ap, fmt);
	parse_params(ap, fmt, list);
	print_result(fmt, list);
	va_end(ap);
	len = count_output(fmt, list);
	free_list(list);
	return (len);
}

t_params	*fill_params(char *fmt)
{
	t_params	*list;
	t_params	*tmp;
	int			i;

	i = 0;
	list = NULL;
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			tmp = get_params(fmt, i);
			i = tmp->last_index;
			list = push_list(list, tmp);
		}
		i++;
	}
	return (list);
}

void		parse_params(va_list ap, char *fmt, t_params *list)
{
	int i;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (list && i == list->start_index)
		{
			if (list->type == 's' || list->type == '%' || list->type == 'c')
				parse_string(ap, list);
			else if (list->type == 'i' || list->type == 'd')
				parse_numbers(ap, list);
			else if (list->type == 'o' || list->type == 'u' ||
				list->type == 'x' || list->type == 'X')
				parse_unsi(ap, list);
			else if (list->type == 'p')
				put_ll(list, (long long)va_arg(ap, void *));
			else if (list->type == 'f')
				parse_double(ap, list);
			i = list->last_index;
			list = list->next;
		}
		i++;
	}
}

void		print_result(char *fmt, t_params *list)
{
	int i;
	int j;

	i = 0;
	while (fmt[i] != '\0')
	{
		if (list && i == list->start_index)
		{
			if (list->result)
			{
				j = 0;
				while (list->result[j] != '\0')
				{
					list->result[j] == -1 ?
					ft_putchar('\0') : ft_putchar(list->result[j]);
					j++;
				}
			}
			i = list->last_index;
			list = list->next;
		}
		else
			ft_putchar(fmt[i]);
		i++;
	}
}

int			count_output(char *fmt, t_params *list)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (fmt[i] != '\0')
	{
		if (list && i == list->start_index)
		{
			count += list->size;
			i = list->last_index;
			list = list->next;
		}
		else
			count++;
		i++;
	}
	return (count);
}
