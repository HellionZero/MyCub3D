/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:10:26 by lsarraci          #+#    #+#             */
/*   Updated: 2026/01/29 19:22:55 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	key_press_hook(mlx_key_data_t keydata, void *param)
{
	return (0);
}

int	key_release_hook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
	{
		mlx_t *mlx;

		mlx = (mlx_t *)param;
		mlx_close_window(mlx);
	}
	return (0);
}

int	mouse_move_hook(double xdelta, double ydelta, void *param)
{
	return (0);
}

int	window_close_hook(void *param)
{
	if (param)
	{
		mlx_t *mlx;

		mlx = (mlx_t *)param;
		mlx_close_window(mlx);
	}
	return (0);
}

int	loop_hook(void *param)
{
	mlx_t	*mlx;
	
	mlx = (mlx_t *)param;
	(void)mlx;	
	return (0);
}