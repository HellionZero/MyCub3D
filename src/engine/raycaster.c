/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:41:07 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/14 20:15:06 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"
# include <stdint.h>

static void	clear_image(mlx_image_t *image, uint32_t color)
{
	uint32_t	x;
	uint32_t	y;

	if (!image)
		return ;
	for (y = 0; y < image->height; ++y)
	{
		for (x = 0; x < image->width; ++x)
			mlx_put_pixel(image, x, y, color);
	}
}

static void	draw_dir_line(mlx_image_t *image, const t_camera *cam)
{
	int		cx;
	int		cy;
	double	dx;
	double	dy;
	int		i;
	int		x;
	int		y;

	if (!image || !cam)
		return ;
	cx = (int)(image->width / 2);
	cy = (int)(image->height / 2);
	dx = cam->dir_x;
	dy = cam->dir_y;
	for (i = 0; i < 100; ++i)
	{
		x = cx + (int)(dx * i);
		y = cy + (int)(dy * i);
		if (x < 0 || y < 0 || x >= (int)image->width || y >= (int)image->height)
			break ;
		mlx_put_pixel(image, (uint32_t)x, (uint32_t)y, 0xFFFFFFFF);
	}
}

void	init_raycast(t_game *game)
{
	(void)game;
}

void	render_frame(t_game *game)
{
	if (!game || !game->window.image)
		return ;

	clear_image(game->window.image, 0x000000FF);
	draw_dir_line(game->window.image, &game->engine.player.camera);
}
