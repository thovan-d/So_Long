/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:59:39 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/23 16:08:56 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mapping mapping;

	mapping.p = 0;
	if (argc != 2)
	{
		ft_printf("Error\nNo Input");
		return (0);
	}
	mapping.map = find_make_map(argv[1], &mapping);
	free(mapping.map);
	return (0);
}
