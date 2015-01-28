/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 14:00:11 by dlevy             #+#    #+#             */
/*   Updated: 2015/01/26 12:30:08 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"fdf.h"

int		event(t_env *e)
{
	int	keycode;

	keycode = 0;
	// //draw(e->mlx, e->win);
	if (keycode == 65307)
		exit(0);
	return (0);
	
}

/*int	mousse_hook(int button, int x, int y, t_env *e)
{	
}*/
