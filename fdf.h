/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 12:41:40 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/11 17:55:13 by dlevy            ###   ########.fr       */
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

typedef struct	s_env
{
	void		*win;
	void		*mlx;
}				t_env;

typedef struct	s_map
{
	t_3dpos		**map;
	t_3dpos		max;
}				t_map;

typedef struct	s_line
{
	int			x0;
	int			y0;
	int			x1;
	int			y1;
	int			sx;
	int			sy;
	int			dx;
	int			dy;
	int			err;
	int			e2;
	int			x;
	int			y;
	int			len;
}				t_line;

void			draw_line(t_line *d, t_env *c);
void			create_map(t_map map, int fd);
void			ft_put_3d_map(t_map *map);
void			ft_3d_line(t_3dpos pos1, t_3dpos pos2);
int				ft_3d_to_2d(t_3dpos po1);

#endif
