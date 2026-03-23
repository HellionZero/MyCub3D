/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 18:40:29 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/23 16:16:12 by lsarraci         ###   ########.fr       */
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

void	log_player_state(t_player *player)
{
	if (!player)
		return ;
	ft_printf("pos=%.2f,%.2f dir=%.2f,%.2f plane=%.2f,%.2f\n",
		player->camera.x,
		player->camera.y,
		player->camera.dir_x,
		player->camera.dir_y);
}
