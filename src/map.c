#include "../include/fdf.h"

t_map	    *map_init(void)
{
	t_map   *map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		ft_print_error(ERR_MAP);
    t_map->width = 0;
    t_map->height = 0;
    return (map);
}

int         read_map(int fd)
{
    char    *line;
    int     result;

    while ((result = get_next_line(fd, &line)) == 1)
    {
        if (ft_strsplit(line, ' '))
            ft_print_error(ERR_SPLIT);
    }
    return (result);
}
/*
** TODO: rewrite ft_strsplit for readind from GNL for 2d array
*/