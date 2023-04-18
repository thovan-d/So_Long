/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:25:59 by thovan-d          #+#    #+#             */
/*   Updated: 2023/04/18 15:29:15 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_up(mlx_key_data_t key, t_mapping *mapping)
{
	if (key.key == MLX_KEY_W && mapping->map[mapping->player_y - 1][mapping->player_x] != '1')
	{
		mapping->moves++;
		mapping->player_y--;
		mapping->images.mario_img->instances[0].y -=64;
		if (mapping->map[mapping->player_y][mapping->player_x ] == 'C')
			collected(mapping);
		if (mapping->map[mapping->player_y][mapping->player_x ] == 'E')
			exit_check(mapping);
	}
}

void	key_down(mlx_key_data_t key, t_mapping *mapping)
{
	if (key.key == MLX_KEY_S && mapping->map[mapping->player_y + 1][mapping->player_x] != '1')
	{
		mapping->moves++;
		mapping->player_y++;
		mapping->images.mario_img->instances[0].y +=64;
		if (mapping->map[mapping->player_y][mapping->player_x ] == 'C')
			collected(mapping);
		if (mapping->map[mapping->player_y][mapping->player_x ] == 'E')
			exit_check(mapping);
	}
}

void	key_left(mlx_key_data_t key, t_mapping *mapping)
{
	if (key.key == MLX_KEY_A && mapping->map[mapping->player_y][mapping->player_x - 1] != '1')
	{
		mapping->moves++;
		mapping->player_x--;
		mapping->images.mario_img->instances[0].x -=64;
		if (mapping->map[mapping->player_y][mapping->player_x ] == 'C')
			collected(mapping);
		if (mapping->map[mapping->player_y][mapping->player_x ] == 'E')
			exit_check(mapping);
	}
}

void	key_right(mlx_key_data_t key, t_mapping *mapping)
{
	if (key.key == MLX_KEY_D && mapping->map[mapping->player_y][mapping->player_x + 1] != '1')
	{
		mapping->moves++;
		mapping->player_x++;
		mapping->images.mario_img->instances[0].x +=64;
		if (mapping->map[mapping->player_y][mapping->player_x ] == 'C')
			collected(mapping);
		if (mapping->map[mapping->player_y][mapping->player_x ] == 'E')
			exit_check(mapping);
	}
}

void	key_pressed(mlx_key_data_t key, void* param)
{
	t_mapping *mapping;

	mapping = param;
	if (key.action != MLX_PRESS)
		return;
	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(mapping->mlx);
	key_up(key, mapping);
	key_down(key, mapping);
	key_left(key, mapping);
	key_right(key, mapping);
}