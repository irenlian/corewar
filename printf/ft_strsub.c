/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:39:11 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 20:39:12 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	int				j;
	char			*fresh;

	i = start;
	j = 0;
	fresh = (char *)malloc(sizeof(char) * len + 1);
	if (s == NULL || fresh == NULL)
		return (NULL);
	while (s[i] != '\0' && i < start + len)
	{
		fresh[j] = s[i];
		j++;
		i++;
	}
	fresh[j] = '\0';
	while (i < start + len)
	{
		fresh[j] = '\0';
		i++;
		j++;
	}
	return (fresh);
}
