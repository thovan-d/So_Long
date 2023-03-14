/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:41:19 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/07 14:48:06 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define BUFFER_SIZE 0

#include "get_next_line.h"

// trim_malloc:
// - i first find the actual length of the gotten line using strlen,
// i use this to accurately malloc (protected) the trimed string.
// - i copy over line into the new trimed string, placing a \0 at the end.
// - now i free the line and returned the trimed string.

char	*trim_malloc(char *line)
{
	char	*trimed;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(line);
	trimed = malloc((length + 1) * sizeof(char));
	if (trimed == NULL)
		return (free(line), NULL);
	while (line[i] != '\0')
	{
		trimed[i] = line[i];
		i++;
	}
	trimed[i] = '\0';
	free(line);
	return (trimed);
}

// Trim_Buffer:
// - In the main while-loop I look for a \n, if I find one I plus my index i
// one more time and proceed to move everything starting from index i to
// the beginning of bufffer up until the terminating character.
// - after the move of characters for the next line i replace
// the unnecessary with \0 cleaning up my buffer.

void	trim_buffer(char *buffer)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while (i < BUFFER_SIZE)
	{
		if (buffer[i] == '\n')
		{
			i++;
			while (buffer[i] != '\0' && i < BUFFER_SIZE)
			{
				buffer[d] = buffer[i];
				d++;
				i++;
			}
			while (buffer[d] != '\0' && d < BUFFER_SIZE)
			{
				buffer[d] = '\0';
				d++;
			}
		}
		i++;
	}
}

// end_of_file:
// - Once this funciton is called i first check if i've read something 
// or if my read failed, if so i clear the buffer, free line and return NULL.
// - If this isnt the case, meaning we have just reached the end of the file,
// i shorten the buffer by adding the \0 on the bytes_read(th) index, and
// proceed the concatenate the buffer to the line.
// - Then i check if the first index of buffer != \n, if this is true
// i clear the buffer.

char	*end_of_file(char *buffer, char *line, int bytes_read)
{
	if ((bytes_read <= 0 && *line == '\0')
		|| bytes_read == -1)
	{
		buffer[0] = '\0';
		return (free(line), NULL);
	}
	buffer[bytes_read] = '\0';
	line = ft_strjoin (line, buffer);
	if (buffer[0] != '\n')
		buffer[0] = '\0';
	return (line);
}

// read_in_buffer:
// this function reads the given file into the buffer.
// - Due to the strchr function as parameter in the while loop it only
// until we encounter a \n.
// - Before reading we check if there is anyhting left/added to the buffer 
// that we need to concatenate to the line.
// - Within the loop i also check if the bytes_read (result from
// the read function) is less than the buffer_size. if this is
// so we know we have either reached the end of the file
// or the read function has failed and i call the end_of_file function
// - If all goes wel and i have encountered a \n i exit the loop and proceed
//  to concatenate the buffer to the line.

char	*read_in_buffer(char *buffer, int fd, char *line)
{
	int		bytes_read;

	bytes_read = 1;
	while (ft_strchr(buffer, '\n') == 0)
	{
		if (buffer[0] != '\0')
			line = ft_strjoin(line, buffer);
		if (line == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < BUFFER_SIZE)
		{
			line = end_of_file(buffer, line, bytes_read);
			if (line == NULL)
				return (NULL);
			return (line);
		}
	}
	line = ft_strjoin(line, buffer);
	return (line);
}

// Get_next_line:
// - to start i check if we have recieved a valid file descriptor 
// and if the buffer is greater then 0, if this isnt so, return NULL.
// - safely malloc line with BUFFER_SIZE + 1. If this is succesful i
// set index 0 of line to \0, otherwise trash values wil be added to my line.
// - i call my read function, i check if it has returned NULL, if so
// i clear my buffer and return NULL.
// - i clean up my buffer using my trum_buffer function.
// - Lastly before returning the new line i trim the malloc of the gotten 
// line to prevent leaks.

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (line == NULL)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	line[0] = '\0';
	line = read_in_buffer(buffer, fd, line);
	if (line == NULL)
	{
		buffer[0] = '\0';
		return (NULL);
	}
	trim_buffer(buffer);
	line = trim_malloc(line);
	return (line);
}

// // // Tester Main
// #include <stdio.h>
// #include <fcntl.h>

// int	main ()
// {
// 	int		fd;
// 	int		x;
// 	char	*line_fd = "line";

// 	x = 1;
// 	fd = open("map.ber", O_RDONLY);
// 	while (line_fd)
// 	{
// 		printf("line %d: %s", x, line_fd = get_next_line(fd));
// 		x++;
// 	}
// 	close(fd);
// 	return (0);
// }