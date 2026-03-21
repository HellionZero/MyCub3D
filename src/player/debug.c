/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:40:29 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 18:40:33 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	log_player_input(t_player *player)
{
	if (!player)
		return ;
	ft_printf("[debug input] f=%d b=%d l=%d r=%d tl=%d tr=%d\n",
		player->input.forward,
		player->input.backward,
		player->input.left,
		player->input.right,
		player->input.turn_left,
		player->input.turn_right);
}

static void	print_fixed2(const char *label, double value)
{
	int	intpart;
	int	frac;

	intpart = (int)value;
	frac = (int)((value - intpart) * 100);
	if (frac < 0)
		frac = -frac;
	ft_printf("%s%d.%02d", label, intpart, frac);
}

void	log_player_state(t_player *player)
{
	if (!player)
		return ;
	ft_printf("[debug state] ");
	print_fixed2("pos:x=", player->camera.x);
	ft_printf(" ");
	print_fixed2("y=", player->camera.y);
	ft_printf(" | ");
	print_fixed2("dir:x=", player->camera.dir_x);
	ft_printf(" ");
	print_fixed2("y=", player->camera.dir_y);
	ft_printf("\n");
}
