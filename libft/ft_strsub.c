/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:03:36 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/13 04:33:35 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*damn;
	size_t	i;

	damn = (char*)malloc(sizeof(char) * (len + 1));
	if (!s || damn == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		damn[i] = s[start];
		i++;
		start++;
	}
	damn[i] = '\0';
	return (damn);
}
