/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:56:33 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/14 21:00:57 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_remove_nl(char *s)
{
	int	i;

	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			// ft_printf("temp=%s", s);
			return (s);
		}
		i++;
	}
	// ft_printf("temp=%s", s);
	return (s);
}

int	check_side_walls(char **map, int x, int y)
{
	while (y >= 1)
	{
		if(map[y][0] != '1' || map[y][x] != '1')
		{
			ft_printf("Error\nMissing side wall");
			exit(0);
		}
		y--;
	}
	return(0);
}

int	check_if_rectangular(char *file, int x)
{
	int		fd;
	char	*temp;

	fd = open(file, O_RDONLY);
	temp = get_next_line(fd);
	x = ft_strlen(temp);
	while (temp)
	{
		temp = get_next_line(fd);
		// trim \n from temp.
		// het gaat miss door de new line bro!!
		temp = ft_remove_nl(temp);
		if (x != ft_strlen(temp))
		{
			ft_printf("Error\nNot rectangular");
			exit(0);
		}
	}
	free (temp);
	close(fd);
	return (x);
}