/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:40:35 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/14 20:22:52 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	update_player(t_player *player, t_map *map, double dt)
{
	double	old_x;
	double	old_y;
	double	dx;
	double	dy;
	double	step;

	step = player->input.speed * dt;
	old_x = player->camera.x;
	old_y = player->camera.y;
	if (player->input.forward)
		move_forward(player, map, step);
	if (player->input.backward)
		move_backward(player, map, step);
	dx = player->camera.x - old_x;
	dy = player->camera.y - old_y;
	if (dx != 0.0 || dy != 0.0)
	{
		ft_printf("Player moved (dt=%.3f): dx=%.3f dy=%.3f => pos=(%.2f, %.2f)\n",
			dt, dx, dy, player->camera.x, player->camera.y);
	}
	else if (player->input.forward || player->input.backward
		|| player->input.left || player->input.right)
	{
		ft_printf("Player movement blocked (dt=%.3f) pos=(%.2f, %.2f)\n",
			dt, player->camera.x, player->camera.y);
	}
}