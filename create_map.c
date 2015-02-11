/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 14:41:21 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/10 14:59:29 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_map(int	fd, char **argv)
{
	int		c;
	int		**tab_i;
	char	*line;
	char	**tab_c;

	while (get_next_line(fd, &line) > 0)
	{
		mod_line(line);
		tab_c = ft_strsplit(line, ' ');
		ft_fill_map(tab_i, tab_c, argv);
	}
}
