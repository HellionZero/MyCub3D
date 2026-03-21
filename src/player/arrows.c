/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:27:53 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 18:37:21 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static int	handle_arrow_press(t_player *player, int key)
{
	if (key == MLX_KEY_UP || key == MLX_KEY_W)
		player->input.forward = 1;
	else if (key == MLX_KEY_DOWN || key == MLX_KEY_S)
		player->input.backward = 1;
	else if (key == MLX_KEY_A)
		player->input.left = 1;
	else if (key == MLX_KEY_D)
		player->input.right = 1;
	else if (key == MLX_KEY_LEFT)
		player->input.turn_left = 1;
	else if (key == MLX_KEY_RIGHT)
		player->input.turn_right = 1;
	return (0);
}

static int	handle_arrow_release(t_player *player, int key)
{
	if (key == MLX_KEY_UP || key == MLX_KEY_W)
		player->input.forward = 0;
	else if (key == MLX_KEY_DOWN || key == MLX_KEY_S)
		player->input.backward = 0;
	else if (key == MLX_KEY_A)
		player->input.left = 0;
	else if (key == MLX_KEY_D)
		player->input.right = 0;
	else if (key == MLX_KEY_LEFT)
		player->input.turn_left = 0;
	else if (key == MLX_KEY_RIGHT)
		player->input.turn_right = 0;
	return (0);
}

int	handle_arrow_events(t_player *player, int key, int action)
{
	if (action == MLX_PRESS)
		return (handle_arrow_press(player, key));
	else if (action == MLX_RELEASE)
		return (handle_arrow_release(player, key));
	return (0);
}
