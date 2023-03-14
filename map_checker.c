/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:49:13 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/14 17:13:32 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_freq_chars2(char **map, int x, int y, int i)
{
	int	e;
	int	c;

	e = 0;
	c = 0;
	while (y >= 1)
	{
		while (i < x)
		{
			if (map[y][i] == 'E')
				e++;
			if (map[y][i] == 'C')
				c++;
			i++;
		}
		i = 0;
		y--;
	}
	if (e != 1 || c < 1)
	{
		ft_printf("Error\nInvalid Map");
		exit(0);
	}
	return (0);
}

int	check_freq_chars1(char **map, int x, int y)
{
	int	i;
	int	p;

	i = 0;
	p = 0;
	while (y >= 1)
	{
		while (i < x)
		{
			if (map[y][i] == 'P')
				p++;
			i++;
		}
		i = 0;
		y--;
	}
	if (p != 1)
	{
		ft_printf("Error\nInvalid Map");
		exit(0);
	}
	return (0);
}

int	check_mid_chars(char **map, int x, int y)
{
	int	i;

	i = 0;
	while (y >= 1)
	{
		while (i < x)
		{
			if (map[y][i] != '1' && map[y][i] != '0'
			&& map[y][i] != 'E' && map[y][i] != 'P'
			&& map[y][i] != 'C' && map[y][i] != '\n')
			{
				ft_printf("Error\nWrong Contents");
				exit(0);
			}
			i++;
		}
		i = 0;
		y--;
	}
	return (0);
}

int	check_last_wall(char *map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (map[i] != '1' && map[i] != '\0')
		{
			ft_printf("Error\nlast wall");
			exit(0);
		}
		i++;
	}
	return (0);
}

int	check_1st_wall(char *map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (map[i] != '1' && map[i] != '\n')
		{
			ft_printf("Error\nfirst line");
			exit(0);
		}
		i++;
	}
	return (0);
}
