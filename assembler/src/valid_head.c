/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_head.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:59:20 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:59:22 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_status_head(char *line)
{
	int status;
	int count_ch;

	status = 1;
	count_ch = count_char(line, '"');
	if (count_ch == 2)
		status = 3;
	else if (count_ch == 1)
		status = 2;
	return (status);
}

void	fill_head_status(int *h_status, char *line, int i)
{
	if (h_status[0] == 2 && ft_strchr(line, '"'))
		h_status[0] = 3;
	else if (h_status[1] == 2 && ft_strchr(line, '"'))
		h_status[1] = 3;
	else if (!is_comment(((char *)(line))[0]))
	{
		if (ft_strstr(line, NAME_CMD_STRING))
			h_status[0] = get_status_head(line);
		else if (ft_strstr(line, COMMENT_CMD_STRING))
			h_status[1] = get_status_head(line);
		else if (((char *)(line))[0] != '\0' &&
		!h_status[0] && !h_status[1])
			show_error("Not valid head at line: ", i);
	}
}

int		valid_head(t_list *champ)
{
	int i;
	int h_status[2];

	i = 0;
	h_status[0] = 0;
	h_status[1] = 0;
	while (champ && ++i)
	{
		fill_head_status(h_status, champ->content, i);
		if (h_status[0] == 3 && h_status[1] == 3)
			return (i);
		champ = champ->next;
	}
	return (show_error("Not valid head", -1));
}
