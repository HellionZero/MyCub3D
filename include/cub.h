/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:14:45 by lsarraci          #+#    #+#             */
/*   Updated: 2026/02/06 16:02:40 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libs/libft/libft.h"
# include "../libs/ft_printf/ft_printf.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# include "raycaster.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

typedef struct s_window
{
	mlx_t	*mlx;
	mlx_image_t	*image;
}	t_window;

typedef struct s_game
{
	t_window	window;
	// Add more game-related fields here (e.g., player position, map, etc.)
}	t_game;

/* ================ hooks manager =============================*/

void	key_event_handler(mlx_key_data_t keydata, void *param);
void	close_hook(void *param);
void	setup_hooks(t_game *game);

/* ==============  window manager =============================*/

int	create_window(t_window *window, int width, int height);
void	destroy_window(t_window *window);

#endif