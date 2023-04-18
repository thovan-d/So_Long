/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_make_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:45 by thovan-d          #+#    #+#             */
/*   Updated: 2023/04/18 15:25:28 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**fill_map(t_mapping *mapping, char *file)
{
	int		fd;
	int		i;
	char	*temp;

	i = 0;
	fd = open(file, O_RDONLY);
	temp = malloc((mapping->x + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	while (i <= mapping->y)
	{
		temp = get_next_line(fd);
		if (temp != NULL)
			mapping->map[i] = temp;
		i++;
	}
	close(fd);
	free(temp);
	return (mapping->map);
}

char	**allocate_map(int x, int y)
{
	int		i;
	char	**map;

	i = 0;
	map = (char **)malloc((y + 1) * sizeof(char *));
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

char	**find_make_map(char *file, t_mapping *mapping)
{
	mapping->y = find_y(file);
	mapping->x = find_x(file);
	if (mapping->x == -1)
		return (printf("Invalid Map"), NULL);
	mapping->map = allocate_map(mapping->x, mapping->y);
	mapping->map = fill_map(mapping, file);
	if (!mapping->map)
		return (0);
	check_1st_wall (mapping->map[0], mapping->x);
	check_last_wall (mapping->map[mapping->y - 1], mapping->x);
	check_mid_chars (mapping->map, mapping->x, (mapping->y - 2));
	check_freq_chars1 (mapping->map, mapping->x, (mapping->y - 2));
	check_freq_chars2 (mapping->map, mapping->x,
		(mapping->y - 1), '0', mapping);
	// (mapping->map, mapping->x,(mapping->y - 1), '0', mapping);
	check_side_walls(mapping->map, (mapping->y - 2));
	check_if_rectangular(mapping->map, (mapping->y - 1), (mapping->x - 1));
	mapping->map_backup = map_backup(mapping, file);
	find_start(mapping, mapping->map_backup,
		(mapping->y - 1), mapping->x);
	check_collectables(mapping);
	return (mapping->map);
}
