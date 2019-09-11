/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:39:03 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 20:41:36 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			res = i;
			while (haystack[res] == needle[j] && needle[j] != '\0')
			{
				res++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char*)(&haystack[i]));
			j = 0;
		}
		i++;
	}
	return (NULL);
}
