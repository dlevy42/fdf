/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 13:18:15 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/05 19:01:13 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_map(t_map *map, t_env *lib)
{
	t_line	*pts;
	int		i;
	int		j;
	int		factor;

	factor = 1;
	i = 0;
	pts->y = 50;
	pts->len = 10;
	while (i < map->max.y)
	{
		j = 0;
		pts->x = 50;
		while (j < map->max.x[i])
		{
			pts->x += ((map->map[i][j]) * factor);
			pts->y += (map->map[i][j]) * (factor / 2);
			if (j < map->max.x[i] - 1)
				draw_line(pts, lib);
			if (i < map->max.y - 1)
				draw_line(pts, lib);
			pts->x += 10;
			j++;
		}
		i++;
		pts->y += 10;
	}
}
