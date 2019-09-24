/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 19:56:59 by pdemian           #+#    #+#             */
/*   Updated: 2018/11/04 18:16:56 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	len;
	size_t	x;

	if (s == NULL)
		return (NULL);
	x = 0;
	i = 0;
	len = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (len > 0 &&
	(s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t'))
		len--;
	if (len <= i)
		len = 0 + i;
	str = ft_strnew(len - i);
	if (str == NULL)
		return (NULL);
	while (i < len)
		str[x++] = s[i++];
	return (str);
}
