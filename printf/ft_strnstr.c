/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 21:50:37 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 21:50:46 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;
	int j;
	int res;

	i = -1;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[++i] != '\0' && i < (int)len)
	{
		if (haystack[i] == needle[j])
		{
			res = i;
			while (haystack[res] == needle[j] &&
				needle[j] != '\0' && res < (int)len)
			{
				res++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char*)(&haystack[i]));
			j = 0;
		}
	}
	return (NULL);
}
