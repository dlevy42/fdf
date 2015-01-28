/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 12:41:40 by dlevy             #+#    #+#             */
/*   Updated: 2015/01/27 19:05:29 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# define BUF_SIZE 10

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

typedef	struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
}			t_point;

typedef struct s_map
{
	int		**map;
	int		nblines;
	int		*dimlines;
}			t_map;

void		draw_line(int x0, int y0, int x1, int y1, t_env *c);
void		create_map(t_list *list, t_map *map);
void		print_map(t_map *map, t_env *Xlib);

#endif
