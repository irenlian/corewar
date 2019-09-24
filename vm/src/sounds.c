/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolozhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 21:44:19 by ppolozhe          #+#    #+#             */
/*   Updated: 2019/09/24 21:44:20 by ppolozhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void voice_of_game(t_vm *vm)
{
	if (vm->vs->sounds)
	{
		system("pkill afplay");
		system("afplay sounds/game_voice.mp3 &> /dev/null &");
	}
}

void voice_of_victory(t_vm *vm)
{
	if (!vm->vs->sounds)
	{
		system("pkill afplay");
		system("afplay sounds/victory_voice.mp3 &> /dev/null &");
	}
}