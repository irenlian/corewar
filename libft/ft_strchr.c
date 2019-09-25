/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 12:37:02 by pdemian           #+#    #+#             */
/*   Updated: 2019/01/26 18:56:20 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char*)s;
	while (*str)
	{
		if (*str == (char)c)
		{
			if (*str + 1 == '\0')
				return (0);
			else
				return (str);
		}
		str++;
	}
	if ((char)c == *str)
		return (str);
	return (0);
}
