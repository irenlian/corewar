/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:08:40 by pdemian           #+#    #+#             */
/*   Updated: 2018/10/31 19:29:32 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (*str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 - *str2 == 0)
		return (1);
	return (0);
}
