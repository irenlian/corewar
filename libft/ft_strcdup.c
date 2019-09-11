/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 18:19:34 by pdemian           #+#    #+#             */
/*   Updated: 2019/07/03 18:19:37 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcdup(const char *s, char c)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	i = -1;
	len = 0;
	while (s[len] != c)
		len++;
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (++i < len)
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
