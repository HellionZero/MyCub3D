/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:59:37 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/11 15:50:05 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_map	*parse_map(const char *filename, t_game *game, char **args)
{
	t_map	*map;
	size_t	i;

	i = 0;
	if (args == NULL || args[1] == NULL)
	{
		ft_printf("Error: No map file provided\n");
		return (NULL);
	}
	filename = args[1];
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		ft_printf("Error: Failed to allocate memory for map structure\n");
		return (NULL);
	}
	return (map);
}
