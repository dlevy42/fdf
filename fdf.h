#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"

# define BUFF_SIZE 10

typedef struct	s_env
{
	void	*win;
	void	*mlx;
}		t_env;

int	key_hook(int keycode);
void	create_map(int fd, char **av);
void	mod_line(char *line);
void    ft_fill_map(int **tab_int, char **tab_c);
int	count_line(char **argv);
int	count_char(char **str);

#endif
