/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 18:15:12 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/14 20:05:57 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static char *g_grid[] = {
    "111111",
    "100001",
    "101101",
    "100001",
    "111111",
    NULL
};

void init_map(t_map *map)
{
    map->height = 5;
    map->width = 6;
    map->grid = g_grid;
}

void	init_player(t_player *player, t_map *map)
{
    (void)map;
    player->camera.x = 2.5;
    player->camera.y = 2.5;
    player->camera.dir_x = 1.0;
    player->camera.dir_y = 0.0;
    player->camera.fov = 66.0 * (acos(-1.0) / 180.0);
    {
        double plane_len = tan(player->camera.fov * 0.5);
        player->camera.plane_x = -player->camera.dir_y * plane_len;
        player->camera.plane_y = player->camera.dir_x * plane_len;
    }
    player->input.forward = 0;
    player->input.backward = 0;
    player->input.left = 0;
    player->input.right = 0;
    player->input.turn_left = 0;
    player->input.turn_right = 0;
    player->input.speed = 0.1;
    player->input.rot_speed = 0.05;
}

void	game_loop(void *param)
{
	static double	last_time = 0.0;
	double		current_time;
	double		dt;
	t_game	*game;

	game = (t_game *)param;
	current_time = mlx_get_time();
	dt = (last_time > 0.0) ? (current_time - last_time) : 0.0;
	last_time = current_time;
	update_player(&game->engine.player, &game->engine.map, dt);
	render_frame(game);
}
