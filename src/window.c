/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:29:49 by lsarraci          #+#    #+#             */
/*   Updated: 2026/02/06 15:37:40 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	create_window(t_window *window, int width, int height)
{
	window->mlx = mlx_init(width, height, "Cub3D", true);
	if (!window->mlx)
	{
		ft_printf("Error initializing MLX\n");
		return (1);
	}
	window->image = mlx_new_image(window->mlx, width, height);
	if (!window->image)
	{
		ft_printf("Error creating image\n");
		mlx_terminate(window->mlx);
		return (1);
	}
	if (mlx_image_to_window(window->mlx, window->image, 0, 0) < 0)
	{
		ft_printf("Error putting image to window\n");
		mlx_terminate(window->mlx);
		return (1);
	}
	return (0);
}

void	destroy_window(t_window *window)
{
	if (window->image)
	{
		mlx_delete_image(window->mlx, window->image);
		window->image = NULL;
	}
	if (window->mlx)
	{
		mlx_terminate(window->mlx);
		window->mlx = NULL;
	}
}