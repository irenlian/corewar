/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_operation_secondary.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:59:48 by dlian             #+#    #+#             */
/*   Updated: 2019/09/26 18:59:50 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	valid_type_add(char *args, int line_index)
{
	int i;
	int count_sep_ch;

	count_sep_ch = 0;
	i = -1;
	if (!valid_reg_arg(args))
		show_error("Arg error at line: ", line_index);
	while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR)
		;
	if (!valid_reg_arg(&args[i + 1]))
		show_error("Arg error at line: ", line_index);
	while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR)
		;
	if (!valid_reg_arg(&args[i + 1]))
		show_error("Arg error at line: ", line_index);
	i = -1;
	while (args[++i] != '\0' && !is_comment(args[i]))
	{
		if (args[i] == SEPARATOR_CHAR)
			count_sep_ch++;
	}
	if (count_sep_ch > 3)
		show_error("Arg error at line: ", line_index);
}

void	valid_type_and(char *args, int line_index)
{
	int i;
	int count_sep_ch;

	count_sep_ch = 0;
	i = -1;
	if (!valid_reg_arg(args) && !valid_ind_arg(args) && !valid_dir_arg(args))
		show_error("Arg error at line: ", line_index);
	while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR)
		;
	if (!valid_reg_arg(&args[i + 1]) &&
	!valid_ind_arg(&args[i + 1]) && !valid_dir_arg(&args[i + 1]))
		show_error("Arg error at line: ", line_index);
	while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR)
		;
	if (!valid_reg_arg(&args[i + 1]))
		show_error("Arg error at line: ", line_index);
	i = -1;
	while (args[++i] != '\0' && !is_comment(args[i]))
	{
		if (args[i] == SEPARATOR_CHAR)
			count_sep_ch++;
	}
	if (count_sep_ch > 3)
		show_error("Arg error at line: ", line_index);
}

void	valid_type_ldi(char *args, int line_index)
{
	int i;
	int count_sep_ch;

	count_sep_ch = 0;
	i = -1;
	if (!valid_reg_arg(args) && !valid_ind_arg(args) && !valid_dir_arg(args))
		show_error("Arg error at line: ", line_index);
	while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR)
		;
	if (!valid_reg_arg(&args[i + 1]) && !valid_dir_arg(&args[i + 1]))
		show_error("Arg error at line: ", line_index);
	while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR)
		;
	if (!valid_reg_arg(&args[i + 1]))
		show_error("Arg error at line: ", line_index);
	i = -1;
	while (args[++i] != '\0' && !is_comment(args[i]))
	{
		if (args[i] == SEPARATOR_CHAR)
			count_sep_ch++;
	}
	if (count_sep_ch > 3)
		show_error("Arg error at line: ", line_index);
}

void	valid_type_sti(char *args, int line_index)
{
	int i;
	int count_sep_ch;

	count_sep_ch = 0;
	i = -1;
	if (!valid_reg_arg(args))
		show_error("Arg error at line: ", line_index);
	while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR)
		;
	if (!valid_reg_arg(&args[i + 1]) &&
	!valid_ind_arg(&args[i + 1]) && !valid_dir_arg(&args[i + 1]))
		show_error("Arg error at line: ", line_index);
	while (args[++i] != '\0' && args[i] != SEPARATOR_CHAR)
		;
	if (!valid_reg_arg(&args[i + 1]) && !valid_dir_arg(&args[i + 1]))
		show_error("Arg error at line: ", line_index);
	i = -1;
	while (args[++i] != '\0' && !is_comment(args[i]))
	{
		if (args[i] == SEPARATOR_CHAR)
			count_sep_ch++;
	}
	if (count_sep_ch > 3)
		show_error("Arg error at line: ", line_index);
}

void	valid_type_aff(char *args, int line_index)
{
	int i;
	int count_sep_ch;

	count_sep_ch = 0;
	i = -1;
	if (!valid_reg_arg(args))
		show_error("Arg error at line: ", line_index);
	i = -1;
	while (args[++i] != '\0' && !is_comment(args[i]))
	{
		if (args[i] == SEPARATOR_CHAR)
			count_sep_ch++;
	}
	if (count_sep_ch > 0)
		show_error("Arg error at line: ", line_index);
}
