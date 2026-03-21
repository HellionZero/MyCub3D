/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:40:35 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 18:34:29 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

void	rotate_player(t_player *player, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	if (!player || angle == 0)
		return ;
	old_dir_x = player->camera.dir_x;
	player->camera.dir_x = player->camera.dir_x * cos(angle)
		- player->camera.dir_y * sin(angle);
	player->camera.dir_y = old_dir_x * sin(angle)
		+ player->camera.dir_y * cos(angle);
	old_plane_x = player->camera.plane_x;
	player->camera.plane_x = player->camera.plane_x * cos(angle)
		- player->camera.plane_y * sin(angle);
	player->camera.plane_y = old_plane_x * sin(angle)
		+ player->camera.plane_y * cos(angle);
}

static void	move_manager(t_player *player, t_map *map, double dt)
{
	double	move_step;

	if (!player || dt <= 0)
		return ;
	move_step = player->input.speed * dt;
	if (player->input.forward)
		move_forward(player, map, move_step);
	if (player->input.backward)
		move_backward(player, map, move_step);
	if (player->input.left)
		strafe_left(player, map, move_step);
	if (player->input.right)
		strafe_right(player, map, move_step);
}

static void	rotate_manager(t_player *player, double dt)
{
	double	rot_step;

	if (!player || dt <= 0)
		return ;
	rot_step = player->input.rot_speed * dt;
	if (player->input.turn_left)
		rotate_player(player, -rot_step);
	if (player->input.turn_right)
		rotate_player(player, rot_step);
}

static void	strafe_manager(t_player *player, t_map *map, double dt)
{
	double	move_step;

	if (!player || dt <= 0)
		return ;
	move_step = player->input.speed * dt;
	if (player->input.left)
		strafe_left(player, map, move_step);
	if (player->input.right)
		strafe_right(player, map, move_step);
}

void	update_player(t_player *player, t_map *map, double dt)
{
	move_manager(player, map, dt);
	rotate_manager(player, dt);
	strafe_manager(player, map, dt);
	log_player_input(player);
	log_player_state(player);
}
