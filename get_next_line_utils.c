/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:04:09 by thovan-d          #+#    #+#             */
/*   Updated: 2023/01/30 15:55:27 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == (char)c)
			return ((char *)&s[x]);
		x++;
	}
	if (s[x] == (char)c)
		return ((char *)&s[x]);
	return (0);
}

int	ft_strlen(char *s)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
		x++;
	return (x);
}

// Second half of str_join
// - Adds buffer to the end of line in join.

char	*concatenate_buffer(char *join, char *buffer, int i)
{
	int	j;

	j = 0;
	while (buffer[j] != '\0')
	{
		if (buffer[j] == '\n')
		{
			join[i + j] = buffer[j];
			j++;
			break ;
		}
		join[i + j] = buffer[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

// ft_strjoin
// - Slightly adjusted string join function.
// - i essentially malloc for join using strlen on both line and buffer
// - i copy line over into join, afterwards i free line.

char	*ft_strjoin(char *line, char *buffer)
{
	int		i;
	char	*join;

	i = 0;
	join = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * sizeof(char));
	if (join == NULL)
		return (free(line), NULL);
	while (line[i] != '\0')
	{
		join[i] = line[i];
		i++;
	}
	join = concatenate_buffer(join, buffer, i);
	free (line);
	return (join);
}
