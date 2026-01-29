/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:15:12 by lsarraci          #+#    #+#             */
/*   Updated: 2026/01/29 19:23:28 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	init_mlx(void)
{
	mlx_t *mlx;

	mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "My Cub3D", true);
	if (!mlx)
		return (1);
	mlx->window = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "My Cub3D");
	mlx->context = mlx_init_context();
	return (0);
}

int	set_loop_hooks(mlx_t *mlx)
{
	if (!mlx)
		return (1);
	mlx_loop_hook(mlx, loop_hook, NULL);
	mlx_key_hook(mlx, key_press_hook, NULL);
	return (0);
}

int	init_hooks(mlx_t *mlx)
{
	if (init_mlx() != 0)
		return (1);
	if (set_loop_hooks(mlx) != 0)
		return (1);
	return (0);
}
