/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:35:13 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/21 18:36:53 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub.h"

static int	is_walkable(t_map *map, double x, double y)
{
	int	gx;
	int	gy;

	if (!map || !map->grid || map->width <= 0 || map->height <= 0)
		return (1);
	gx = (int)floor(x);
	gy = (int)floor(y);
	if (gx < 0 || gy < 0 || gy >= map->height || gx >= map->width)
		return (0);
	if (map->grid[gy][gx] == '1')
		return (0);
	return (1);
}

void	move_forward(t_player *player, t_map *map, double step)
{
	double	nx;
	double	ny;

	if (!player || step <= 0)
		return ;
	nx = player->camera.x + player->camera.dir_x * step;
	ny = player->camera.y + player->camera.dir_y * step;
	if (is_walkable(map, nx, player->camera.y))
		player->camera.x = nx;
	if (is_walkable(map, player->camera.x, ny))
		player->camera.y = ny;
	ft_printf("[move_forward] pos= ");
	ft_printf("%.2f,%.2f\n", player->camera.x, player->camera.y);
}

void	move_backward(t_player *player, t_map *map, double step)
{
	double	nx;
	double	ny;

	if (!player || step <= 0)
		return ;
	nx = player->camera.x - player->camera.dir_x * step;
	ny = player->camera.y - player->camera.dir_y * step;
	if (is_walkable(map, nx, player->camera.y))
		player->camera.x = nx;
	if (is_walkable(map, player->camera.x, ny))
		player->camera.y = ny;
	ft_printf("[move_backward] pos= ");
	ft_printf("%.2f,%.2f\n", player->camera.x, player->camera.y);
}

void	strafe_left(t_player *player, t_map *map, double step)
{
	double	nx;
	double	ny;

	if (!player || step <= 0)
		return ;
	nx = player->camera.x - player->camera.plane_x * step;
	ny = player->camera.y - player->camera.plane_y * step;
	if (is_walkable(map, nx, player->camera.y))
		player->camera.x = nx;
	if (is_walkable(map, player->camera.x, ny))
		player->camera.y = ny;
	ft_printf("[strafe_left] pos= ");
	ft_printf("%.2f,%.2f\n", player->camera.x, player->camera.y);
}

void	strafe_right(t_player *player, t_map *map, double step)
{
	double	nx;
	double	ny;

	if (!player || step <= 0)
		return ;
	nx = player->camera.x + player->camera.plane_x * step;
	ny = player->camera.y + player->camera.plane_y * step;
	if (is_walkable(map, nx, player->camera.y))
		player->camera.x = nx;
	if (is_walkable(map, player->camera.x, ny))
		player->camera.y = ny;
	ft_printf("[strafe_right] pos= ");
	ft_printf("%.2f,%.2f\n", player->camera.x, player->camera.y);
}
