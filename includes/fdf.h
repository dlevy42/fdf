#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;

}					t_env;

typedef struct 		s_stock
{
	int 	w;
	int 	k;
	int		**tab;
}					t_stock;

#define WIDTH 500
#define HEIGHT 500
#define NAME "42"

#define K_ESC 65307

#endif
