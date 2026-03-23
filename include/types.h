/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:56:59 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/23 17:16:06 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define RED 0xFF0000FF
# define GREEN 0xFF00FF00
# define BLUE 0xFFFF0000
# define WHITE 0xFFFFFFFF
# define YELLOW 0xFFFFFF00
# define BLACK 0xFF000000

typedef enum e_direction	t_direction;
typedef enum e_texture_type	t_texture_type;
typedef enum e_node_type	t_node_type;

enum e_direction {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum e_node_type {
	NODE_MAP,
	NODE_PLAYER,
	NODE_SPRITE,
	NODE_ENEMY,
	NODE_MINIMAP
};

enum e_texture_type {
	TEX_WALL,
	TEX_SPRITE
};

#endif