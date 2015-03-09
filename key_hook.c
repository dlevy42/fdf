#include "fdf.h"

int	key_hook(int keycode)
{
	if (keycode == 65307)
		exit (0);
	return (0);
}
