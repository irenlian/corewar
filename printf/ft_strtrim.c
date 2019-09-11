/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:39:24 by dlian             #+#    #+#             */
/*   Updated: 2018/11/04 20:39:26 by dlian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		i;
	int		start;
	int		end;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	start = i;
	end = ft_strlen(s);
	while (end - 1 > start && (s[end - 1] == ' ' ||
		s[end - 1] == '\n' || s[end - 1] == '\t'))
		end--;
	res = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[start] != '\0' && start < end)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
