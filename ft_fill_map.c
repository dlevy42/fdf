/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:43 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/10 14:59:30 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_line(char *argv)
{
	int	i;
	int fd;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		i++;
	return (i);
}

void	ft_fill_mapp(int **tab_i, char **tab_c, char **argv)
{
	static int	w;

	if (w == 0)
	{
		w = count_line(argv);
		if (!(a_i = (int **)malloc(sizeof(int *) * w)))
			return (NULL);
	}
}
