/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:22:20 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/13 16:52:30 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_map(int fd, char **av)
{
	char		*line;
	char		**tab_c;
	int		**tab_int;
	static int	w;

	if (w == 0)
	{
		w = count_line(av);
		if (!(tab_int = (int **)malloc(sizeof(int *) * w)))
			return ;
	}
	while (get_next_line(fd, &line) > 0)
	{
		mod_line(line);
		tab_c = ft_strsplit(line, ' ');
		ft_fill_map(tab_int, tab_c);
	}
}
