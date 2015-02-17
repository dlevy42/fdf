#include "fdf.h"

void			clean(char *line)
{
	int			i;

	i = 0;
	while (line[i] != '\0')
	{
		if ((line[i] >= '0' && line[i] <= '9') || line[i] == '-')
			i++;
		else
		{
			line[i] = ' ';
			i++;
		}
	}
}

int		count_char(char **array)
{
	int		i;

	i = 0;
	while(array[i] != '\0')
		i++;
	return (i);
}

void	ft_fill_map(t_stock *stock, char **array)
{
	static int		i;
	int				j;
	int				nb;

	j = 0;
	nb = count_char(array);
	stock->tab[i] = (int *)malloc(sizeof(int) * nb);
	while(j <= nb - 1)
	{
		stock->tab[i][j] = ft_atoi(array[j]);
		j++;
	}
	i++;
}

int		count_line(char **av)
{
	int		j;
	int		fd;
	char	*line;

	j = 0;
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
		j++;
	return (j);
}

void	stock_tab(t_stock *stock, char **av)
{
	int		fd;
	int		ret;
	char 	*line;
	char	**array;

	line = (void *)0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_err_or(av);
	if (stock->w == 0)
	{
		stock->w = count_line(av);
		if (!(stock->tab = (int **)malloc(sizeof(int *) * stock->w)))
			return ;
	}
	while ((ret = get_next_line(fd, &line)) >= 0)
	{
		clean(line);
		array = ft_strsplit(line, ' ');
		ft_fill_map(stock, array);
		printf("%d\n", count_line(array));
		if (ret <= 0)
			break ;
	}
	close (fd);
	return ;
}