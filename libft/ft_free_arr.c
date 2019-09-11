/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:51:29 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/07 23:52:12 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_free_arr(char ***array)
{
	size_t	i;
	char	**tmp;

	i = 0;
	tmp = *array;
	while (tmp[i])
	{
		free(tmp[i]);
		tmp[i++] = NULL;
	}
	free(tmp);
	*array = NULL;
}
