/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:05:20 by thovan-d          #+#    #+#             */
/*   Updated: 2023/04/18 15:22:28 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <memory.h>
# include <unistd.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "get_next_line.h"
# include "ft_printf.h"
# define WIDTH 512
# define HEIGHT 512


typedef struct	s_textures
{
	mlx_texture_t* mario;
	mlx_texture_t* background;
	mlx_texture_t* exit;	
	mlx_texture_t* wall;
	mlx_texture_t* collectable;
}	t_textures;

typedef struct	s_images
{
	mlx_image_t* mario_img;
	mlx_image_t* background_img;
	mlx_image_t* exit_img;	
	mlx_image_t* wall_img;
	mlx_image_t* collectale_img;
}	t_images;

typedef struct	s_mapping
{
	int	x;
	int y;
	int p;
	int	collectables;
	int	player_y;
	int	player_x;
	int	moves;
	char **map;
	char **map_backup;
	mlx_t* mlx;
	t_images images;
	t_textures textures;
// make flood map copy	
}	t_mapping;

void	make_game(t_mapping *mapping);
char	**find_make_map(char *file, t_mapping *mapping);
char	**allocate_map(int x, int y);
char	**map_backup(t_mapping *mapping, char *file);
int		check_1st_wall(char *map, int x);
int		check_last_wall(char *map, int x);
int		check_mid_chars(char **map, int x, int y);
int		check_freq_chars1(char **map, int x, int y);
int		check_freq_chars2(char **map, int x, int y, int i, t_mapping *mapping);
int		check_side_walls(char **map, int y);
int		check_if_rectangular(char **map, int y, int x); 
int		find_start(t_mapping *mapping, char **map, int x, int y);
void	check_collectables(t_mapping *mapping);
void	key_pressed(mlx_key_data_t key, void* param);
void	collected(t_mapping *mapping);
void	exit_check(t_mapping *mapping);
void	delete_textures_images(t_mapping *mapping);
void	free_maps(t_mapping *mapping);
#endif