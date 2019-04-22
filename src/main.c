#include "../inc/fdf.h"
size_t			map_size(const char *file, t_map *map);

int			main(int ac, char **av)
{
	t_map	*map;

	errno = 0;
	if (ac == 2)
	{
		map = map_init(av[1]);
		if (read_map(av[1], map) == -1)
			print_error(ERR_MAP_READ);
	}
	else
		print_error(ERR_USAGE);
	return (0);

}
