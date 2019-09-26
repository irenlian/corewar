/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:59:09 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:59:11 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	set_int(int fd, int code, int bytes)
{
	char c;

	while (--bytes > 0)
	{
		c = code >> (bytes * 8);
		write(fd, &c, 1);
	}
	c = code;
	write(fd, &c, 1);
}

int		get_int_from_bytes(char *byte_code)
{
	int res;
	int i;
	int len;

	i = 0;
	res = 0;
	len = ft_strlen(byte_code);
	while (--len >= 0)
	{
		if (byte_code[len] == '1')
			res += ft_power(2, i);
		i++;
	}
	return (res);
}

void	set_name(int fd, char *name, int max_length)
{
	int		i;
	char	c;

	c = 0;
	i = 0;
	write(fd, name, ((i = ft_strlen(name)) < max_length) ? i : max_length);
	while (i < max_length)
	{
		write(fd, &c, 1);
		i++;
	}
	i = 0;
	write(fd, &c, 1);
	write(fd, &c, 1);
	write(fd, &c, 1);
	write(fd, &c, 1);
}

int		is_comment(char c)
{
	if (c == COMMENT_CHAR || c == ALT_COMMENT_CHAR)
		return (1);
	return (0);
}

int		show_error(const char *error, int err_index)
{
	if (err_index < 0)
		ft_printf("%tERROR: %t%s%t\n", B_RED, B_WHITE, error, EOC);
	else
		ft_printf("%t%s%d%t\n", B_RED, error, err_index + 1, EOC);
	exit(0);
}
