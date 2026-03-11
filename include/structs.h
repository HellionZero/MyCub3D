/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:04:38 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/11 15:44:57 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/MLX42/include/MLX42/MLX42.h"

typedef struct s_window		t_window;
typedef struct s_game		t_game;
typedef struct s_line		t_line;
typedef struct s_minimap	t_minimap;
typedef struct s_map		t_map;
typedef struct s_player		t_player;
typedef struct s_texture	t_texture;
typedef struct s_camera		t_camera;
typedef struct s_ray		t_ray;
typedef struct s_color		t_color;
typedef struct s_sprite		t_sprite;

struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
};

// Add more game-related fields here (e.g., player position, map, etc.)

struct s_game
{
	t_window	window;
};

struct s_line
{
	double	x1;
	double	y1;
	double	x2;
	double	y2;
};

struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
};

struct s_map
{
	int		width;
	int		height;
	char	**grid;
};


struct s_minimap
{
	t_map	*map;
	int		size;
	double	scale;
};

#endif
