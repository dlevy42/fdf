/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlevy <dlevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:51:39 by dlevy             #+#    #+#             */
/*   Updated: 2015/02/13 16:52:31 by dlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>

# define BUF_SIZE 10

typedef struct	s_env
{
	void		*win;
	void		*mlx;
}				t_env;

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

void	mod_line(char *line);
void	create_map(int fd, char **argv);
int		count_line(char **argv);
int		count_char(char **str);
void	ft_fill_map(int **tab_int, char **tab_c);
int		key_hook(int keycode);
int		expose_hook(t_env *c);
void	draw_line(t_line *d, t_env *e);

#endif
