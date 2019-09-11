/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:27:18 by dlian             #+#    #+#             */
/*   Updated: 2019/03/05 11:27:21 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_params
{
	char			type;
	char			flags[5];
	int				min_width;
	int				precision;
	char			modify[3];
	int				start_index;
	int				last_index;
	char			*result;
	int				size;
	struct s_params	*next;
}				t_params;

int				get_numsize(long long num, int precision, char type);
int				get_resultsize(long long num, int len, t_params *list,
	char *strnum);
char			*ft_ftoa(long double n, t_params *list);
void			set_float(t_params *list, long double num);
char			*ft_itoal(long long n, int len, char type);
int				ft_printf(char *fmt, ...);
void			print(t_params *list, char *fmt, ...);
t_params		*fill_params(char *fmt);
t_params		*get_params(char *fmt, int i);
void			put_flag(char *container, char flag);
void			put_modify(char *container, char mode);
t_params		*create_list(int start_index);
t_params		*push_list(t_params *start, t_params *node);
void			free_list(t_params *list);
void			print_str(t_params *list, char *strp);
char			*set_width(int size, char c);
void			put_char(t_params *list, char ch);
void			print_arg(t_params *list);
void			put_ll(t_params *list, long long num);
void			put_str(t_params *list, char *strp);
void			parse_string(va_list ap, t_params *list);
void			parse_params(va_list ap, char *fmt, t_params *list);
void			parse_numbers(va_list ap, t_params *list);
void			parse_double(va_list ap, t_params *list);
void			parse_unsi(va_list ap, t_params *list);
void			print_result(char *fmt, t_params *list);
int				count_output(char *fmt, t_params *list);
void			validate(t_params *list);
void			put_ull(t_params *list, unsigned long long num);
int				ft_pow(int n, int to);
void			fill_result(int is_positive, t_params *list,
	char *result, char	*strnum);
void			revers_fill_result(int is_positive, t_params *list,
	char *result, char	*strnum);
#endif
