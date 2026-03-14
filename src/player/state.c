/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:31:51 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/14 20:26:34 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void    move_forward(t_player *player, t_map *map, double step)
{
	double new_x;
	double new_y;

	new_x = player->camera.x + player->camera.dir_x * step;
	new_y = player->camera.y + player->camera.dir_y * step;
	if (map->grid[(int)player->camera.y][(int)new_x] == '0')
		player->camera.x = new_x;
	if (map->grid[(int)new_y][(int)player->camera.x] == '0')
		player->camera.y = new_y;
}

void	move_backward(t_player *player, t_map *map, double step)
{
	double new_x;
	double new_y;

	new_x = player->camera.x - player->camera.dir_x * step;
	new_y = player->camera.y - player->camera.dir_y * step;
	if (map->grid[(int)player->camera.y][(int)new_x] == '0')
		player->camera.x = new_x;
	if (map->grid[(int)new_y][(int)player->camera.x] == '0')
		player->camera.y = new_y;
}