/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 11:25:37 by dlevy             #+#    #+#             */
/*   Updated: 2015/01/27 19:05:21 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(int x0, int y0, int x1, int y1, t_env *c)

{
	c->dx = (int)fabs((double)x1 - (double)x0);
	c->dy = (int)fabs((double)x1 - (double)y0);
	c->sx = x0 < x1 ? 1 : -1;
	c->sy = y0 < y1 ? 1 : -1;
	c->err = (c->dx > c-> dy ? c->dx : -(c->dy)) / 2;	
	while (1)
	{
		mlx_pixel_put(c->mlx, c->win, x0, y0, 0xFF0000);
		if (x0 == x1 && y0 == y1)
			break ;
		c->e2 = c->err;
		if (c->e2 > -(c->dx))
		{
			c->err -= c->dy;
			x0 += c->sx;
		}
		if (c->e2 < c->dy)
		{
			c->err += c->dx;
			y0 += c->sy;
		}
	}
}
