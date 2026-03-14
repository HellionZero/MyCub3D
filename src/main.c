/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:13:52 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/14 18:48:45 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	game_loop(void *param);

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
	init_map(&game->engine.map);
	init_player(&game->engine.player, &game->engine.map);
	setup_hooks(game);
	mlx_loop_hook(game->window.mlx, game_loop, game);
	mlx_loop(game->window.mlx);
	destroy_window(&game->window);
	free(game);
	return (0);
}
