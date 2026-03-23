/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:04:38 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/23 18:27:52 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "types.h"

/* ---------- Structure definitions ----------*/

/* MAIN STRUCTS	*/
typedef struct s_window		t_window;
typedef struct s_engine		t_engine;
typedef struct s_game		t_game;

/* NODE STRUCTS	*/
typedef struct s_transform	t_transform;
typedef struct s_scenenode	t_scenenode;
typedef struct s_mapnode	t_mapnode;

/* DRAW STRUCTS	*/
typedef struct s_pointf		t_pointf;
typedef struct s_line		t_line;
typedef struct s_texture	t_texture;

/* MAP STRUCTS	*/
typedef struct s_minimap	t_minimap;
typedef struct s_map		t_map;

/* RAYCASTING STRUCTS	*/
typedef struct s_player		t_player;
typedef struct s_movement	t_movement;
typedef struct s_camera		t_camera;
typedef struct s_ray		t_ray;
typedef struct s_color		t_color;
typedef struct s_sprite		t_sprite;

struct s_window
{
	mlx_t		*mlx;
	mlx_image_t	*image;
};

struct s_transform
{
	t_pointf	*position;
	double		rotation;
	double		scale;
};

struct s_scenenode
{
	t_node_type			type;
	void				*data;
	struct s_scenenode	*left_child;
	struct s_scenenode	*right_child;
};

struct s_map
{
	char	*cells;
	int		is_wall;
};

struct s_camera
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	fov;
};

struct s_movement
{
	int		forward;
	int		backward;
	int		left;
	int		right;
	int		turn_left;
	int		turn_right;
	double	speed;
	double	rot_speed;
};

struct s_player
{
	t_camera	camera;
	t_movement	input;
};

struct s_engine
{
	t_map		map;
	t_player	player;
};

struct s_game
{
	t_window	window;
	t_engine	engine;
};

struct s_pointf
{
	double	x;
	double	y;
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

struct s_texture
{
	mlx_image_t	*image;
	int			width;
	int			height;
};


struct s_minimap
{
	t_map	*map;
	int		size;
	double	scale;
	int		x_offset;
	int		y_offset;
};

struct s_ray
{
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	t_texture_type	texture_type;
};

#endif
