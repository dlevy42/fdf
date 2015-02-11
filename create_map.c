/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 12:53:05 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/10 18:06:35 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3dpos		**fill_map(t_list *lst, t_3dpos pt)
{
	int			i;
	t_3dpos		**tab;

	i = 0;
	tab = (t_3dpos**)malloc(sizeof(t_3dpos*) * pt.y);
	while (i < pt.y)
	{
		tab[i] = (t_3dpos*)malloc(sizeof(t_3dpos) * pt.x);
		i++;
	}
	while (lst)
	{
		pt = *((t_3dpos*)lst->content);
		tab[pt.y][pt.x] = pt;
		lst = lst->next;
	}
	return (tab);
}

void		create_map(t_map map, int fd)
{
	int		i;
	char	**tab;
	char	*tmp;
	t_list	*lst;

	lst = NULL;
	map.max.y = 0;
	while (get_next_line(fd, &tmp))
	{
		i = 0;
		map.max.x = 0;
		tab = ft_strsplit(tmp, ' ');
		while (tab[i])
		{
			map.max.z = ft_atoi(tab[i]);
			ft_lstadd(&lst, ft_lstnew(&map.max, sizeof(t_3dpos)));
			free(tab[i]);
			i++;
			map.max.x++;
		}
		map.max.y++;
	}
	map.map = fill_map(lst, map.max);
	close(fd);
}
