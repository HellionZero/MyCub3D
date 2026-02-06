/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:10:26 by lsarraci          #+#    #+#             */
/*   Updated: 2026/02/06 15:43:10 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	key_event_handler(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		destroy_window(&game->window);
		exit(0);
	}
}

void	close_hook(void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	destroy_window(&game->window);
	exit(0);
}

void	setup_hooks(t_game *game)
{
	mlx_key_hook(game->window.mlx, key_event_handler, game);
	mlx_close_hook(game->window.mlx, close_hook, game);
}