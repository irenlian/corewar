/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_operation_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:59:40 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:59:41 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_dir_status(char ch, int status)
{
	if (status == 0 && ch == DIRECT_CHAR)
		status = 1;
	else if (status == 1 && ch == LABEL_CHAR)
		status = 2;
	else if ((status == 2 || status == 4) && ft_strchr(LABEL_CHARS, ch))
		status = 4;
	else if ((status == 1 && ft_strchr("-0123456789", ch))
	|| (status == 3 && ft_strchr("0123456789", ch)))
		status = 3;
	else if (status == 0 && (ch == ' ' || ch == '\t'))
		status = -1;
	else
		status = -2;
	return (status);
}

int		valid_dir_arg(char *dir)
{
	int i;
	int status;
	int tmp_status;

	i = -1;
	status = 0;
	while (dir[++i] != '\0')
	{
		tmp_status = get_dir_status(dir[i], status);
		if (tmp_status == -1)
			continue ;
		else if (tmp_status == -2)
			break ;
		else
			status = tmp_status;
	}
	while (dir[i] != '\0' && (dir[i] == ' ' || dir[i] == '\t'))
		i++;
	if ((!is_comment(dir[i]) &&
		dir[i] != SEPARATOR_CHAR && dir[i] != '\0') ||
		(status != 3 && status != 4))
		return (0);
	return (1);
}

int		get_ind_status(char ch, int status)
{
	if (status == 0 && (ch == ' ' || ch == '\t'))
		status = -1;
	else if (status == 0 && ch == LABEL_CHAR)
		status = 1;
	else if ((status == 1 || status == 3) && ft_strchr(LABEL_CHARS, ch))
		status = 3;
	else if ((status == 0 && (ft_isdigit(ch) || ch == '-')) ||
	(status == 2 && ft_isdigit(ch)))
		status = 2;
	else
		status = -2;
	return (status);
}

int		valid_ind_arg(char *arg)
{
	int i;
	int status;
	int	tmp_status;

	i = -1;
	status = 0;
	while (arg[++i] != '\0')
	{
		tmp_status = get_ind_status(arg[i], status);
		if (tmp_status == -1)
			continue ;
		else if (tmp_status == -2)
			break ;
		else
			status = tmp_status;
	}
	while (arg[i] != '\0' && (arg[i] == ' ' || arg[i] == '\t'))
		i++;
	if ((!is_comment(arg[i]) &&
		arg[i] != SEPARATOR_CHAR && arg[i] != '\0') ||
		(status != 2 && status != 3))
		return (0);
	return (1);
}

int		valid_reg_arg(char *arg)
{
	int i;
	int status;

	i = -1;
	status = 0;
	while (arg[++i] != '\0')
	{
		if (arg[i] == ' ' || arg[i] == '\t')
			continue ;
		else if (status == 0 && arg[i] == 'r')
			status = 1;
		else if ((status >= 1) && ft_isdigit(arg[i]))
			status++;
		else
			break ;
	}
	while (arg[i] != '\0' && (arg[i] == ' ' || arg[i] == '\t'))
		i++;
	if ((!is_comment(arg[i]) &&
		arg[i] != SEPARATOR_CHAR && arg[i] != '\0') ||
		status < 2 || status > 3)
		return (0);
	return (1);
}
