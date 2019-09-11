/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:37:14 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 20:37:16 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*fresh;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	j = ft_strlen(s1) + ft_strlen(s2);
	fresh = (char *)malloc(sizeof(char) * j + 1);
	if (fresh == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		fresh[j++] = s1[i++];
	}
	i = 0;
	while (s2[i] != '\0')
	{
		fresh[j++] = s2[i++];
	}
	fresh[j] = '\0';
	return (fresh);
}
