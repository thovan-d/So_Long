/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:43:30 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/23 16:56:55 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_p(int p)
{
	if (p == 0)
		p = 1;
	return (p);
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

int	find_start(char **map, int y, int x, int p)
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
				result = flood_fill(y, i, p, map);
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
