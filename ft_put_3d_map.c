/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_3d_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 17:50:45 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/10 19:12:47 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_3d_map(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < (map->max.y - 1))
	{
		x = 0;
		while (x < (map->max.x - 1))
		{
			ft_3d_line(map.map[y][x], map.map[y][x + 1]);
			ft_3d_line(map.map[y][x], map.map[y + 1][x]);
			x++;
		}
		y++;
	}
}
