/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 13:51:49 by dlevy             #+#    #+#             */
/*   Updated: 2015/01/28 18:05:26 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void			create_map(t_list *list, t_map *map)
{
	int		i;
	int		j;
	char	**line;

	i = 0;
	map->nblines = ft_lstlen(list);
	map->map = (int**)malloc(sizeof(int *) * (map->nblines + 1));
	map->dimlines = (int*)malloc(sizeof(int) * (map->nblines + 1));
	while (list)
	{
		j = 0;
		line = ft_strsplit(list->content, ' ');
		(map->map)[i] = (int*)malloc(sizeof(int) * ((map->dimlines)[i] + 1));
		while (line[j])
		{
			map->map[i][j] = ft_atoi(line[j]);
			j++;
		}
		i++;
		list = list->next;
		}
}

void		print_map(t_map *map, t_env *Xlib)
{
	int		i;
	int		j;
	int		x;
	int		y;
	int		len;
	int		factor;

	factor = 1;
	i = 0;
	y = 50;
	len = 10;
	while(i < map->nblines)
	{
		j = 0;
		x = 50;
//		printf("Alive\n");
		while (j < map->dimlines[i])
		{
//			printf("Alive2\n");
			x += ((map->map[i][j]) * factor);
			y += (map->map[i][j]) * (factor / 2);
			if (j < map->dimlines[i] - 1)
				draw_line(x, y, x + len, y, Xlib);
			if(i < map->nblines - 1)
				draw_line(x, y, x, y + len, Xlib);
//			ft_putnbr(x);
//			ft_putchar('\n');
			x += 10;
			j++;
		}
		i++;
		y += 10;
	}
}
