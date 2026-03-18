/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:15:12 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/18 18:36:13 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	render_frame(t_game *game)
{
	mlx_image_t	*image;

	image = game->window.image;
	if (!image)
		return ;
	mlx_image_fill(image, 0x000000FF);
}

void	game_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	render_frame(game);
}
