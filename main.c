/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:48:34 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/10 14:59:35 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int fd;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "fdf");
	if (argc != 2)
	{
		ft_putstr("not enough arg\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open fail\n");
		return (0);
	}
	create_map(fd, argv);
	return (0);
}
