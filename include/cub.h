/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 19:14:45 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/18 18:34:38 by lsarraci         ###   ########.fr       */
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

# include "structs.h"
# include "raycaster.h"
# include "parser.h"
# include "structs.h"
# include "player.h"
# include "types.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

/* ================ hooks manager =============================*/

void		key_event_handler(mlx_key_data_t keydata, void *param);
void		close_hook(void *param);
void		setup_hooks(t_game *game);

/* ==============  window manager =============================*/

int			create_window(t_window *window, int width, int height);
void		destroy_window(t_window *window);

/* ==============  load utilities =============================*/

mlx_image_t	*load_texture(mlx_t *mlx, const char *path);

/* ==============  map loader =============================*/

/* ==============  render functions =============================*/

void	render_frame(t_game *game);
void	game_loop(void *param);

#endif