/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:38:54 by dlian             #+#    #+#             */
/*   Updated: 2018/11/05 00:30:17 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**alloarraystr(char const *s, char c)
{
	char	**res;
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != '\0' && s[i] != c)
				i++;
			size++;
		}
		else
			i++;
	}
	res = (char **)malloc(sizeof(char *) * (size + 1));
	return (res);
}

static int		count_word_size(char const *s, char c, int *i)
{
	int size;

	size = 0;
	while (s[*i] != '\0' && s[*i] != c)
	{
		size++;
		(*i)++;
	}
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		size;

	i = -1;
	j = -1;
	size = 0;
	if (s == NULL)
		return (NULL);
	if (!(res = alloarraystr(s, c)))
		return (NULL);
	while (s[++i] != '\0')
		if (s[i] != c)
		{
			size = count_word_size(s, c, &i);
			if (!(res[++j] = ft_strsub(s, (i--) - size, size)))
				return (NULL);
		}
	res[++j] = NULL;
	return (res);
}
