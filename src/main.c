/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:13:52 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/11 15:19:46 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

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
	setup_hooks(game);
	mlx_loop(game->window.mlx);
	destroy_window(&game->window);
	free(game);
	return (0);
}
