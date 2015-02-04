/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 11:25:37 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/04 15:01:38 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_line *d, t_env *c)

{
	c->dx = (int)fabs((double)d->x1 - (double)d->x0);
	c->dy = (int)fabs((double)d->x1 - (double)d->y0);
	c->sx = d->x0 < d->x1 ? 1 : -1;
	c->sy = d->y0 < d->y1 ? 1 : -1;
	c->err = (c->dx > c->dy ? c->dx : -(c->dy)) / 2;
	while (1)
	{
		mlx_pixel_put(c->mlx, c->win, d->x0, d->y0, 0xFF0000);
		if (d->x0 == d->x1 && d->y0 == d->y1)
			break ;
		c->e2 = c->err;
		if (c->e2 > -(c->dx))
		{
			c->err -= c->dy;
			d->x0 += c->sx;
		}
		if (c->e2 < c->dy)
		{
			c->err += c->dx;
			d->y0 += c->sy;
		}
	}
}
