/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:43:30 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/23 14:01:47 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i = 0;

	ft_printf("\n__________\n\n");
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

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

// vraag iris over structs of zo?!
int	flood_fill(int y, int x, int p, char **map)
{
	if (get_char(y, x, map) == 'E')
		p = set_p(p);
	if (get_char(y, x, map) == '0' || get_char(y, x, map) == 'C'
	|| get_char(y, x, map) == 'P' || get_char(y, x, map) == 'E')
	{
		map = change_char(y, x, map);
		flood_fill(y, x+1, p, map);
		flood_fill(y+1, x, p, map);
		flood_fill(y, x-1, p, map);
		flood_fill(y-1, x, p, map);
	}
	ft_printf("p%d", p);
	return (p);
}
// find P?!
int	find_start(char **map, int y, int x)
{
	int	i;
	int	p;
	int	result;

	i = 0;
	p = 0;
	while (y >= 1)
	{
		while (i < x)
		{
			if (map[y][i] == 'P')
			{	
				result = flood_fill(y, i, p, map);
				ft_printf("result=%d\n", result);
			}
			i++;
		}
		i = 0;
		y--;
	}
	// ft_printf("result=%d\n", result);
	// print_map(map);
	if (result == -1)
	{
		ft_printf("Error\nMap Impossible");
		exit(0);
	}
	return (0);
}
