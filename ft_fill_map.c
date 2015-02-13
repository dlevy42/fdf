/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:39:43 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/13 16:52:34 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_line(char **argv)
{
	int		j;
	int		fd;
	char	*line;

	j = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		j++;
	return (j);
}

int		count_char(char **str)
{
	int		i;

	i = 0;
	while(str[i] != '\0')
		i++;
	return (i);
}

void	ft_fill_map(int **tab_int, char **tab_c)
{
	static int		i;
	int		j;
	int		nb;

	j = 0;
	nb = count_char(tab_c);
	tab_int[i] = (int *)malloc(sizeof(int) * nb);
	while(j <= nb - 1)
	{
		tab_int[i][j] = ft_atoi(tab_c[j]);
		j++;
	}
	i++;
}
