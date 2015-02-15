/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 11:28:46 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/15 11:28:51 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	draw_line(void *mlx, void *win)
{
	int		x;
	int		y;

	y = 100;
	while (y <= 200)
	{
		x = 100;
		while (x <= 200)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}*/

void		draw_line(t_line *d, t_env *e)

{
	d->dx = (int)fabs((double)d->x1 - (double)d->x0);
	d->dy = (int)fabs((double)d->x1 - (double)d->y0);
	d->sx = d->x0 < d->x1 ? 1 : -1;
	d->sy = d->y0 < d->y1 ? 1 : -1;
	d->err = (d->dx > d->dy ? d->dx : -(d->dy)) / 2;
	while (1)
	{	
		if (d->dx < 420 && d->dy < 420)
			ft_putstr("truc");
			mlx_pixel_put(e->mlx, e->win, d->x0, d->y0, 0xFF0000);
		if (d->x0 == d->x1 && d->y0 == d->y1)
			break ;
		d->e2 = d->err;
		if (d->e2 >= -(d->dx))
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


/*void draw_line(int x0, int y0, int x1, int y1) 
{ 
	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = (dx>dy ? dx : -dy)/2, e2;
 
 	for(;;)
  	{
    setPixel(x0,y0);
    if (x0==x1 && y0==y1) 
    	break;
    e2 = err;
    if (e2 >-dx) 
    	err -= dy; x0 += sx;
    if (e2 < dy) 
    	err += dx; y0 += sy; 
	}
}
*/