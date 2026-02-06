/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:13:52 by lsarraci          #+#    #+#             */
/*   Updated: 2026/02/06 16:00:44 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	main(void)
{
	t_game game;
	
	create_window(&game.window, WINDOW_WIDTH, WINDOW_HEIGHT);
	setup_hooks(&game);
	mlx_loop(game.window.mlx);
	destroy_window(&game.window);
	return (0);
}
