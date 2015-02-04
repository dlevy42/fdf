/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 13:18:15 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/04 15:01:46 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_map(t_map *map, t_env *lib)
{
	int		*i;
	int		*j;
	int		x;
	int		y;
	int		len;
	int		factor;

	factor = 1;
	i = 0;
	y = 50;
	len = 10;
	while (*i < map->max.y)
	{
		j = 0;
		x = 50;
		while (*j < map->max.x[i])
		{
			x += ((map->max[i][j]) * factor);
			y += (map->max[i][j]) * (factor / 2);
			if (*j < map->max.x[i] - 1)
				draw_line(x, y, x + len, y, lib);
			if (*i < map->max.y - 1)
				draw_line(x, y, x, y + len, lib);
			x += 10;
			j++;
		}
		i++;
		y += 10;
	}
}
