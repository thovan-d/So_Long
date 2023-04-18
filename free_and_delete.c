/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_delete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:32:46 by thovan-d          #+#    #+#             */
/*   Updated: 2023/04/18 15:23:37 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_textures_images(t_mapping *mapping)
{
	mlx_delete_image(mapping->mlx, mapping->images.mario_img);
	mlx_delete_texture(mapping->textures.mario);
	mlx_delete_image(mapping->mlx, mapping->images.collectale_img);
	mlx_delete_texture(mapping->textures.collectable);
	mlx_delete_image(mapping->mlx, mapping->images.wall_img);
	mlx_delete_texture(mapping->textures.wall);
	mlx_delete_image(mapping->mlx, mapping->images.exit_img);
	mlx_delete_texture(mapping->textures.exit);
	mlx_delete_image(mapping->mlx, mapping->images.background_img);
	mlx_delete_texture(mapping->textures.background);
}

void	free_maps(t_mapping *mapping)
{
	int i;

	i = 0;
	while (mapping->map[i] != '\0')
	{
		free(mapping->map[i]);
		i++;
	}
	i = 0;
	while (mapping->map_backup[i] != '\0')
	{
		free(mapping->map_backup[i]);
		i++;
	}
}