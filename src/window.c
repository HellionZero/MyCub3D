/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 15:29:49 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/11 15:19:10 by lsarraci         ###   ########.fr       */
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

/*
	** Once mlx_loop returns we can perform any necessary cleanup.  In our
	** case the hooks already call destroy_window/exit, so this is mostly
	** defensive.  Free the game struct to avoid leaks in case tests inspect
	** after loop.
	*/
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
