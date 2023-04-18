/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:56:33 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/30 16:57:15 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collectables(t_mapping *mapping)
{
	int	i;

	i = 0;
	while (mapping->map_backup[i])
	{
		if (ft_strchr(mapping->map_backup[i], 67) != 0)
		{
			ft_printf("Error\nMap Impossible");
			exit(0);
		}
		i++;
	}
}

char	*ft_remove_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			return (s);
		}
		i++;
	}
	return (s);
}

int	check_side_walls(char **map, int y)
{
	int	i;

	i = 0;
	while (y >= 1)
	{
		if (map[y][0] != '1')
		{
			ft_printf("Error\nMissing side wall");
			exit(0);
		}
		while (map[y][i] != '\n')
			i++;
		if (map[y][i - 1] != '1')
		{
			ft_printf("Error\nMissing side wall");
			exit(0);
		}
		y--;
		i = 0;
	}
	return (0);
}

int	check_if_rectangular(char **map, int y, int x)
{
	int	i;

	i = 0;
	while (y >= 0)
	{
		while (map[y][i] != '\n' && map[y][i] != '\0')
			i++;
		if (i != x)
		{
			ft_printf("Error\nNot rectangular");
			exit(0);
		}
		i = 0;
		y--;
	}
	return (0);
}
