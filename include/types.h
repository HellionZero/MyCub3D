/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 17:56:59 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/14 17:58:42 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_direction	t_direction;
typedef enum e_texture_type	t_texture_type;

enum e_direction {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

enum e_texture_type {
	TEX_WALL,
	TEX_SPRITE
};

#endif