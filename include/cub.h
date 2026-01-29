/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:14:45 by lsarraci          #+#    #+#             */
/*   Updated: 2026/01/29 19:17:57 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

int	loop_hook(void *param);
int	key_press_hook(mlx_key_data_t keydata, void *param);
int	key_release_hook(mlx_key_data_t keydata, void *param);
int	mouse_move_hook(double xdelta, double ydelta, void *param);
int	window_close_hook(void *param);
int	init_hooks(void);
int	init_mlx(void);

#endif