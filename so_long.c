/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:2023/03/07 13:59:39 by thovan-d          #+#    #+#             */
/*   Updated: 2023/04/13 16:44:20 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_check(t_mapping *mapping)
{
	if (mapping->collectables == 0)
		mlx_close_window(mapping->mlx);
	else
		return;
}

void	collected(t_mapping *mapping)
{
	int	i;
	int	y;
	int	x;
	mlx_instance_t *collectable;

	i = 0;
	x = mapping->player_x *64;
	y = mapping->player_y *64;
	while (1)
	{
		collectable = &mapping->images.collectale_img->instances[i];
		if(collectable->x == x && collectable->y == y && mapping->map[mapping->player_y][mapping->player_x] == 'C')
		{
			mapping->map[mapping->player_y][mapping->player_x] = '0';
			mapping->collectables--;
			collectable->enabled = false;
			return;
		}
		i++;
	}
}

void	f(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{
	t_mapping *mapping;
	t_textures *textures;
	t_images *images;

	mapping = malloc(sizeof(t_mapping));
	textures = malloc(sizeof(t_textures));
	images = malloc(sizeof(t_images));
	mapping->p = 0;
	mapping->moves = 0;
	if (argc != 2)
	{
		ft_printf("Error\nNo Input");
		return (0);
	}
	find_make_map(argv[1], mapping);
	make_game(mapping);
	ft_printf("Moves:%d", mapping->moves);
	// delete_textures_images(mapping);
	free_maps(mapping);
	atexit(f);
	return (EXIT_SUCCESS);
}