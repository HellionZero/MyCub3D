/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:13:52 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 17:36:57 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	game_loop(void *param);

static void	init_engine(t_game *game)
{
	ft_bzero(&game->engine, sizeof(game->engine));
	game->engine.player.camera.x = 1.5;
	game->engine.player.camera.y = 1.5;
	game->engine.player.camera.dir_x = -1.0;
	game->engine.player.camera.dir_y = 0.0;
	game->engine.player.camera.plane_x = 0.0;
	game->engine.player.camera.plane_y = 0.66;
	game->engine.player.input.speed = 3.0;
	game->engine.player.input.rot_speed = 2.0;
}

int	main(void)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
	{
		ft_printf("Error: Failed to allocate memory for game structure\n");
		return (1);
	}
	if (create_window(&game->window, WINDOW_WIDTH, WINDOW_HEIGHT) != 0)
	{
		ft_printf("Error: Failed to create window\n");
		free(game);
		return (1);
	}
	init_engine(game);
	setup_hooks(game);
	mlx_loop_hook(game->window.mlx, game_loop, game);
	mlx_loop(game->window.mlx);
	destroy_window(&game->window);
	free(game);
	return (0);
}
