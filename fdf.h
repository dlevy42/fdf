/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 12:41:40 by dlevy             #+#    #+#             */
/*   Updated: 2015/01/31 12:58:19 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# define BUF_SIZE 10

typedef struct	s_3dpos
{
	int			x;
	int			y;
	int			z;
}				t_3dpos;

typedef struct s_env
{
	void	*win;
	void	*mlx;
	int		sx;
	int		sy;
	int		dx;
	int		dy;
	int		err;
	int		e2;
}			t_env;

typedef struct s_map
{
	t_3dpos		**map;
	t_3dpos		max;
}				t_map;

void		draw_line(int x0, int y0, int x1, int y1, t_env *c);
void		create_map(t_map map, int fd);
void		print_map(t_map *map, t_env *Xlib);

#endif
