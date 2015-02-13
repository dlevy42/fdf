/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:04:22 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/13 16:52:23 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw(void *mlx, void *win)
{
	int		x;
	int		y;

	y = 100;
	while (y == 200)
	{
		x = 100;
		while (x <= 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

// void		draw_line(t_env *e, t_env *d)

// {
// 	d->dx = (int)fabs((double)d->x1 - (double)d->x0);
// 	d->dy = (int)fabs((double)d->x1 - (double)d->y0);
// 	d->sx = d->x0 < d->x1 ? 1 : -1;
// 	d->sy = d->y0 < d->y1 ? 1 : -1;
// 	d->err = (d->dx > d->dy ? d->dx : -(d->dy)) / 2;
// 	while (1)
// 	{
// 		mlx_pixel_put(e->mlx, e->win, d->x0, d->y0, 0xFF0000);
// 		if (d->x0 == d->x1 && d->y0 == d->y1)
// 			break ;
// 		d->e2 = d->err;
// 		if (d->e2 > -(d->dx))
// 		{
// 			d->err -= d->dy;
// 			d->x0 += d->sx;
// 		}
// 		if (d->e2 < d->dy)
// 		{
// 			d->err += d->dx;
// 			d->y0 += d->sy;
// 		}
// 	}
// }