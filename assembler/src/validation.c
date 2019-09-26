/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 19:00:02 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 19:00:03 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		valid_magic(char *magic)
{
	if (magic[0] == '0' && (magic[1] == 'x' || magic[1] == 'X'))
		return (1);
	return (0);
}

int		valid_champ_name(char *name)
{
	int len;

	len = ft_strlen(name);
	if (len < 2 || name[len - 1] != 's' || name[len - 2] != '.')
		return (0);
	return (1);
}

int		count_char(char *line, char c)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (line[++i] != '\0')
	{
		if (line[i] == c)
			count++;
	}
	return (count);
}

void	valid_command_line(char *line, int line_index, t_command *catalog)
{
	int		i;
	int		j;
	char	*pos;

	i = -1;
	j = -1;
	while (line[++j] != '\0')
	{
		if (is_comment(line[j]))
			break ;
		else if (line[j] == LABEL_CHAR)
		{
			valid_label(line, j, line_index);
			i = j;
			break ;
		}
		else if (!ft_strchr(LABEL_CHARS, line[j]))
			break ;
	}
	while (line[++i] != '\0' && (line[i] == ' ' || line[i] == '\t'))
		;
	if (!is_comment(line[i]) && line[i] != '\0')
		valid_operation(&line[i], line_index);
}

void	valid_champ_file(t_list *champ, t_command *catalog)
{
	t_list	*tmp;
	int		i;
	int		j;

	i = -1;
	tmp = champ;
	j = valid_head(champ);
	while (++i < j)
		tmp = tmp->next;
	while (tmp)
	{
		valid_command_line(tmp->content, i, catalog);
		tmp = tmp->next;
		i++;
	}
}
