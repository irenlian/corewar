/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:17:58 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/07 21:57:44 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static inline size_t	count_len(char const *s, char c)
{
	size_t		len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static inline size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	n;

	n = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			n++;
		}
		i++;
	}
	return (n);
}

char					**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		len;
	size_t		p;
	char		**arr;

	if (!s)
		return (NULL);
	p = 0;
	i = 0;
	if (!(arr = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	while (s[p])
	{
		if (s[p] != c)
		{
			len = count_len(s + p, c);
			arr[i] = ft_strsub(s, p, len);
			i++;
			p += len;
		}
		p++;
	}
	arr[i] = NULL;
	return (arr);
}
