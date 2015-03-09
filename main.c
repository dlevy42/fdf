#include "fdf.h"

int	main(int ac, char **av)
{
	int	fd;
	t_env	e;

	e.mlx = mlx_init();
	if (ac != 2)
	{
		ft_putstr("not enough arg\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open fail\n");
		return(0);
	}
	e.win = mlx_new_window(e.mlx, 420, 420, "42");
	mlx_key_hook(e.win, key_hook, &e);
//	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_loop(e.mlx);
	return(0);
}
