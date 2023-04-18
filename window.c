/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:29:05 by thovan-d          #+#    #+#             */
/*   Updated: 2023/04/18 15:22:22 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	project_sprites_2(t_mapping *mapping)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = 0;
	j = 0;
	while (y != mapping->y)
	{
		x = 0;
		i = 0;
		while (x < (mapping->x - 1))
		{
			if (mapping->map[y][x] == 'C')
				mlx_image_to_window(mapping->mlx,
					mapping->images.collectale_img, i, j);
			if (mapping->map[y][x] == 'E')
				mlx_image_to_window(mapping->mlx,
					mapping->images.exit_img, i, j);
			if (mapping->map[y][x] == 'P')
				mlx_image_to_window(mapping->mlx,
					mapping->images.mario_img, i, j);
			i = i + 64;
			x++;
		}
		j = j +64;
		y++;
	}
}

void	project_sprites(t_mapping *mapping)
{
	int y;
	int	x;
	int	i;
	int	j;

	y = 0;
	j = 0;
	
	while (y != mapping->y)
	{
		x = 0;
		i = 0;
		while (x < (mapping->x - 1))
		{
			mlx_image_to_window(mapping->mlx, mapping->images.background_img, i, j);
			if (mapping->map[y][x] == '1')
				mlx_image_to_window(mapping->mlx, mapping->images.wall_img, i, j) ;
			i = i +64;
			x++;
		}
		j = j +64;
		y++;
	}
}

void	load_convert(t_mapping *mapping)
{
	mapping->textures.background = mlx_load_png("grass.png");
	mapping->textures.mario = mlx_load_png("roof_sprite.png");
	mapping->textures.exit = mlx_load_png("exit_sprite.png");
	mapping->textures.collectable = mlx_load_png("collectable_sprite.png");
	mapping->textures.wall = mlx_load_png("wall_sprite.png");
	mapping->images.wall_img = mlx_texture_to_image(mapping->mlx, mapping->textures.wall);
	mapping->images.collectale_img = mlx_texture_to_image(mapping->mlx, mapping->textures.collectable);
	mapping->images.exit_img = mlx_texture_to_image(mapping->mlx, mapping->textures.exit);
	mapping->images.background_img = mlx_texture_to_image(mapping->mlx, mapping->textures.background);
	mapping->images.mario_img = mlx_texture_to_image(mapping->mlx, mapping->textures.mario);
}

void	make_game(t_mapping *mapping)
{
	mapping->mlx = mlx_init(((mapping->x - 1) *64), (mapping->y *64), "gameplay", false);
	if (!mapping->mlx)
        exit(0);
	// printf("[%p]-[%p]", mapping->images.mario_img, images->mario_img);
	load_convert(mapping);
	project_sprites(mapping);
	project_sprites_2(mapping);
	mapping->map[mapping->player_y][mapping->player_x ] = '0';
	mlx_key_hook(mapping->mlx, key_pressed, mapping);
	mlx_loop(mapping->mlx);
	mlx_terminate(mapping->mlx);
}
