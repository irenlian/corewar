/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:59:28 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:59:29 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	valid_label(char *line, int pos_label_char, int line_index)
{
	int status;

	status = 0;
	while (--pos_label_char >= 0)
	{
		if ((status == 0 || status == 1) &&
		ft_strchr(LABEL_CHARS, line[pos_label_char]))
			status = 1;
		else if ((status == 1 || status == 2) &&
		ft_strchr(" \t", line[pos_label_char]))
			status = 2;
		else
			show_error("Label error in line: ", line_index);
	}
}

int		is_exist_label(t_list *code_list, char *label)
{
	t_list *mark_list;

	while (code_list)
	{
		mark_list = ((t_code *)(code_list->content))->mark;
		while (mark_list)
		{
			if (ft_strequ(mark_list->content, label))
				return (1);
			mark_list = mark_list->next;
		}
		code_list = code_list->next;
	}
	return (0);
}

void	valid_existing_labels(t_list *code_list)
{
	t_list	*tmp;
	t_code	*code;
	char	*lable;

	tmp = code_list;
	while (tmp)
	{
		code = (t_code *)tmp->content;
		if (code->arg1 && (lable = ft_strchr(code->arg1, LABEL_CHAR)) &&
		!is_exist_label(code_list, &code->arg1[lable - code->arg1 + 1]))
			show_error("Label doesn't exist", -1);
		if (code->arg2 && (lable = ft_strchr(code->arg2, LABEL_CHAR)) &&
		!is_exist_label(code_list, &code->arg2[lable - code->arg2 + 1]))
			show_error("Label doesn't exist", -1);
		if (code->arg3 && (lable = ft_strchr(code->arg3, LABEL_CHAR)) &&
		!is_exist_label(code_list, &code->arg3[lable - code->arg3 + 1]))
			show_error("Label doesn't exist", -1);
		tmp = tmp->next;
	}
}
