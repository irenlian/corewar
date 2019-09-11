/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:36:44 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 11:36:47 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_ll(t_params *list, long long num)
{
	int		len;
	int		i;
	int		j;
	char	*result;
	char	*strnum;

	i = 0;
	j = 0;
	len = get_numsize(num, list->precision, list->type);
	strnum = ft_itoal(num, len, list->type);
	result = set_width(get_resultsize(num, len, list, strnum), ' ');
	if (list->flags[2] == '-')
		fill_result(((num >= 0) ? 1 : 0), list, result, strnum);
	else
		revers_fill_result(((num >= 0) ? 1 : 0), list, result, strnum);
	free(strnum);
	list->result = result;
	list->size = ft_strlen(result);
}

void	put_str(t_params *list, char *strp)
{
	int		i;
	int		len;
	int		j;
	char	*result;

	len = ft_strlen(strp);
	j = 0;
	if (list->precision >= 0 && len > list->precision && list->type != '%')
		len = list->precision;
	if (list->flags[0] == '0')
		result = set_width(get_resultsize(0, len, list, strp), '0');
	else
		result = set_width(get_resultsize(0, len, list, strp), ' ');
	i = 0;
	if (list->flags[2] != '-')
	{
		while (i++ < list->min_width - len)
			j++;
	}
	i = 0;
	while (i < len)
		result[j++] = strp[i++];
	i = 0;
	list->result = result;
	list->size = ft_strlen(result);
}

void	put_char(t_params *list, char ch)
{
	char	*result;
	int		i;

	i = 0;
	if (!ch)
		ch = -1;
	if (list->min_width > 0)
	{
		result = (list->flags[0] == '0') ? set_width(list->min_width, '0')
		: set_width(list->min_width, ' ');
		if (list->flags[2] == '-')
			result[0] = ch;
		else
			result[list->min_width - 1] = ch;
		list->result = result;
	}
	else
	{
		result = set_width(1, ' ');
		result[0] = ch;
		list->result = result;
	}
	list->size = ft_strlen(result);
	if (ch == 0)
		list->size++;
}
