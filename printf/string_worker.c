/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_worker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:56:42 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 11:56:44 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_result(int is_positive, t_params *list, char *result, char *strnum)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!is_positive || list->flags[3] == '+')
		result[i++] = !is_positive ? '-' : '+';
	if (list->type == 'p')
	{
		result[i++] = '0';
		result[i++] = 'x';
	}
	if (list->flags[1] == '#' && (list->type == 'x' || list->type == 'X'))
	{
		result[i++] = '0';
		result[i++] = list->type;
	}
	if (list->flags[1] == '#' && list->type == 'o' && strnum[0] != '0')
		result[i++] = '0';
	if (list->flags[4] == ' ' && is_positive)
		result[i++] = ' ';
	while (result[i] != '\0' && strnum[j] != '\0')
		result[i++] = strnum[j++];
}

void	revers_fill_result(int is_positive, t_params *list,
	char *result, char *strnum)
{
	int i;
	int j;

	i = ft_strlen(result);
	j = ft_strlen(strnum);
	while (j >= 0)
		result[i--] = strnum[j--];
	while (i >= 0 && list->flags[0] == '0' && list->precision == -1)
		result[i--] = '0';
	if (!is_positive || list->flags[3] == '+')
		result[i >= 0 ? i : 0] = !is_positive ? '-' : '+';
	if (list->type == 'p')
	{
		result[i >= 1 ? i : 1] = 'x';
		result[i - 1] = '0';
	}
	if (list->flags[4] == ' ' && is_positive)
		result[i >= 0 ? i : 0] = ' ';
	if (list->flags[1] == '#' && (list->type == 'x' || list->type == 'X'))
	{
		result[i >= 1 ? i : 1] = list->type;
		result[i - 1] = '0';
	}
	if (list->flags[1] == '#' && list->type == 'o' && strnum[0] != '0')
		result[i >= 0 ? i : 0] = '0';
}
