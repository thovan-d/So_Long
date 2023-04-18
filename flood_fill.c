/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:43:30 by thovan-d          #+#    #+#             */
/*   Updated: 2023/04/18 12:57:02 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_backup(t_mapping *mapping, char *file)
{
	char	**temp;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	temp = allocate_map(mapping->x, mapping->y);
	if (temp == NULL)
		return (0);
	while (i <= mapping->y)
	{
		temp[i] = get_next_line(fd);
		i++;
	}
	return (temp);
}

char	get_char(int y, int x, char **map)
{
	char	a;

	a = map[y][x];
	return (a);
}

char	**change_char(int y, int x, char **map)
{
	map[y][x] = 'X';
	return (map);
}

int	flood_fill(int y, int x, int p, char **map)
{
	if (get_char(y, x, map) == 'E')
	{
		p = 1;
		return (p);
	}
	if (get_char(y, x, map) == '0' || get_char(y, x, map) == 'C'
		|| get_char(y, x, map) == 'P')
	{
		map = change_char(y, x, map);
		p = flood_fill(y, x + 1, p, map);
		p = flood_fill(y + 1, x, p, map);
		p = flood_fill(y, x - 1, p, map);
		p = flood_fill(y - 1, x, p, map);
	}
	return (p);
}

int	find_start(t_mapping *mapping, char **map, int y, int x)
{
	int	i;
	int	result;

	i = 0;
	while (y >= 1)
	{
		while (i < x)
		{
			if (map[y][i] == 'P')
			{	
				mapping->player_y = y;
				mapping->player_x = i;
				result = flood_fill(y, i, mapping->p, map);
			}
			i++;
		}
		i = 0;
		y--;
	}
	if (result == 0)
	{
		ft_printf("Error\nMap Impossible");
		exit(0);
	}
	return (0);
}
