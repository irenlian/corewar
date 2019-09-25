/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:05:19 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/17 17:05:21 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_vs	*init_visual(void)
{
	t_vs *vs;

	if (!(vs = (t_vs *)ft_memalloc(sizeof(t_vs))))
		exit(-1);
	vs->is_run = false;
	vs->speed = CYCLE_LIMIT;
	vs->map_window = NULL;
	vs->info_window = NULL;
	vs->help_window = NULL;
	vs->pixels = 0;
	vs->button = 0;
	vs->quantity = 0;
	vs->carriages_num = 0;
	vs->aff_symbol = 0;
	vs->aff_player = NULL;
	vs->sounds = false;
	vs->display_help = false;
	return (vs);
}
