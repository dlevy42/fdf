/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 11:25:37 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/10 18:07:03 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_line(t_line *d, t_env *c)

{
	d->dx = (int)fabs((double)d->x1 - (double)d->x0);
	d->dy = (int)fabs((double)d->x1 - (double)d->y0);
	d->sx = d->x0 < d->x1 ? 1 : -1;
	d->sy = d->y0 < d->y1 ? 1 : -1;
	d->err = (d->dx > d->dy ? d->dx : -(d->dy)) / 2;
	while (1)
	{
		mlx_pixel_put(c->mlx, c->win, d->x0, d->y0, 0xFF0000);
		if (d->x0 == d->x1 && d->y0 == d->y1)
			break ;
		d->e2 = d->err;
		if (d->e2 > -(d->dx))
		{
			d->err -= d->dy;
			d->x0 += d->sx;
		}
		if (d->e2 < d->dy)
		{
			d->err += d->dx;
			d->y0 += d->sy;
		}
	}
}
