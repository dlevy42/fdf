/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfrimin <bfrimin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 16:57:36 by bfrimin           #+#    #+#             */
/*   Updated: 2015/02/16 20:42:17 by bfrimin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		mlx_put_image(t_env e, unsigned long color, int x, int y)
{
	unsigned char color1;
	unsigned char color2;
	unsigned char color3;

	color1 = (color & 0xFF0000) >> 16;
	color2 = (color & 0xFF00) >> 8;
	color3 = (color & 0xFF) >> 0;

	e.data[y * e.size_line + x * e.bpp / 8] = color3;
	e.data[y * e.size_line + x * e.bpp / 8 + 1] = color2;
	e.data[y * e.size_line + x * e.bpp / 8 + 2] = color1;
}

void		ft_err_or(char **av)
{
	perror(av[1]);
	exit(1);
}

int		key_hook(int	keycode)
{
	if (keycode == K_ESC)
		exit(0);
	return (0);
}

int		expose_hook(t_env *e, t_stock *stock)
{
	draw(stock, e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		main(int ac, char **av)
{
	t_stock 	stock;
	t_env		e;
	
	stock.w = 0;
	stock.k = 0;
	stock_tab(&stock, av);
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, NAME);
	e.img = mlx_new_image(e.mlx, WIDTH, HEIGHT);
	e.data = mlx_get_data_addr(e.img, &(e.bpp), &(e.size_line), &(e.endian));
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
