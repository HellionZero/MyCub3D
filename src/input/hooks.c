/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:10:26 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/23 18:04:42 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static void	key_direction_handler(mlx_key_data_t keydata, t_game *game)
{
	if (keydata.action == MLX_PRESS || keydata.action == MLX_RELEASE)
	{
		handle_arrow_events(&game->engine.player, keydata.key, keydata.action);
	}
}

void	key_event_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		destroy_window(&game->window);
		exit(0);
	}
	else
		key_direction_handler(keydata, game);
}

void	close_hook(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	destroy_window(&game->window);
	exit(0);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->window.mlx, key_event_handler, game);
	mlx_close_hook(game->window.mlx, close_hook, game);
}
