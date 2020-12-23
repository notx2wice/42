#include "../includes/cub3d.h"

int			main(void)
{
	t_window	window;

	set_cub(window.cub, "map.cub");
	printf("%d\n", window.cub->res_width);
}
