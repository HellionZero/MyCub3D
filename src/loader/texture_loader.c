/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarraci <lsarraci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:00:16 by lsarraci          #+#    #+#             */
/*   Updated: 2026/03/11 15:11:55 by lsarraci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

mlx_image_t	*load_texture(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf("Error: Failed to load texture from %s\n", path);
		return (NULL);
	}
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!image)
	{
		ft_printf("Error: Failed to convert texture to image\n");
		return (NULL);
	}
	return (image);
}
