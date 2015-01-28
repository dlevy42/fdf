/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/20 14:44:26 by dlevy             #+#    #+#             */
/*   Updated: 2015/01/27 19:05:19 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc,char **argv)
{
	int		fd;
	char	*line;
	t_list	*list;
	t_list	*tmp;
	t_env	e;
	t_map	map;

	line = NULL;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 420, 420, "fdf");
	if (argc != 2)
	{
		ft_putstr("not enough arg\n");
		return(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open fail\n");
		return(0);
	}
	while(get_next_line(fd, &line) > 0)
	{
		ft_lstadd_back(&list, ft_lstnew(line, ft_strlen(line) + 1));
		free(line);
	}
	tmp = list; 
//	ft_putlist(list);
	create_map(tmp, &map);
	while (1)
		print_map(&map, &e);
	//mlx_loop(e.mlx);
//	close(fd);
	return(0);
}
