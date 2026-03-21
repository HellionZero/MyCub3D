/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 18:37:14 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 17:54:44 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

#include "structs.h"

int handle_arrow_events(t_player *player, int key, int action);
void move_forward(t_player *player, t_map *map, double step);
void move_backward(t_player *player, t_map *map, double step);
void strafe_left(t_player *player, t_map *map, double step);
void strafe_right(t_player *player, t_map *map, double step);
void update_player(t_player *player, t_map *map, double dt);
void rotate_player(t_player *player, double angle);
void log_player_input(t_player *player);
void log_player_state(t_player *player);
void draw_player_debug(mlx_t *mlx, t_player *player);

#endif