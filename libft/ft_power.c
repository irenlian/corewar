/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdemian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:08:41 by pdemian           #+#    #+#             */
/*   Updated: 2019/03/21 18:56:08 by pdemian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int		ft_power(long long int nb, int pow)
{
	long long int		tmp;

	if (pow == 0 || nb == 1)
		return (1);
	tmp = nb;
	while (--pow)
		tmp *= nb;
	return (tmp);
}
