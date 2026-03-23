/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:15:12 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/23 16:19:30 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	render_frame(t_game *game)
{
	mlx_image_t	*image;

	image = game->window.image;
	if (!image)
		return ;
	mlx_image_to_window(game->window.mlx, image, 0, 0);
}

void	game_loop(void *param)
{
	static double	last_time = 0.0;
	double			now;
	double			dt;
	t_game			*game;

	game = (t_game *)param;
	now = mlx_get_time();
	if (last_time > 0.0)
		dt = now - last_time;
	else
	dt = 0.0;
	if (dt < 0.0)
		dt = 0.0;
	last_time = now;
	update_player(&game->engine.player, &game->engine.map, dt);
	log_player_input(&game->engine.player);
	if (dt > 0.05)
		log_player_state(&game->engine.player);
	render_frame(game);
}
