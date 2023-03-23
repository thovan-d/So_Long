/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_make_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:45 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/23 14:00:36 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(char **map, char *file, int y, int x)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(file, O_RDONLY);
	temp = malloc((x + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (i <= y)
	{
		temp = get_next_line(fd);
		if (temp != NULL)
		{
			map[i] = temp;
			ft_printf("%s", map[i]);
		}
		i++;
	}
	close(fd);
	free(temp);
	return (map);
}

char	**allocate_map(int x, int y)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc(y * sizeof(char *));
	if (!map)
		return (NULL);
	while (i < y)
	{
		map[i] = (char *)malloc(x * sizeof(char));
		if (!map)
			return (NULL);
		i++;
	}
	return (map);
}

int	find_x(char *file)
{
	int		fd;
	int		x;
	int		len;
	char	*temp;

	x = 0;
	len = 0;
	temp = "0";
	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	x = ft_strlen(temp);
	while (temp)
	{
		temp = get_next_line(fd);
	}
	free (temp);
	close(fd);
	return (x);
}

int	find_y(char *file)
{
	int		fd;
	int		y;
	char	*temp;

	y = -1;
	temp = "0";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error");
		exit(0);
	}
	while (temp)
	{
		temp = get_next_line(fd);
		y++;
	}
	close(fd);
	return (y);
}

char	**find_make_map(char *file)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	x = 0;
	y = find_y(file);
	x = find_x(file);
	if (x == -1)
		return (printf("Invalid Map"), NULL);
	map = allocate_map(x, y);
	map = fill_map(map, file, y, x);
	if (!map)
		return (0);
	check_1st_wall (map[0], x);
	check_last_wall (map[y - 1], x);
	check_mid_chars (map, x, (y - 2));
	check_freq_chars1 (map, x, (y - 2));
	check_freq_chars2 (map, x, (y - 1), '0');
	check_side_walls(map, (y - 2));
	check_if_rectangular(map, (y - 1), (x - 1));
	find_start(map, (y - 1), x);
	return (map);
}
