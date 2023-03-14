/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 17:05:20 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/14 18:28:11 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include "get_next_line.h"
# include "ft_printf.h"

char	**find_make_map(char *file);
int		check_1st_wall(char *map, int x);
int		check_last_wall(char *map, int x);
int		check_mid_chars(char **map, int x, int y);
int		check_freq_chars1(char **map, int x, int y);
int		check_freq_chars2(char **map, int x, int y, int i);
int		check_side_walls(char **map, int x, int y);
int		check_if_rectangular(char *file, int x);

#endif