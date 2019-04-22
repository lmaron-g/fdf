#include "../inc/fdf.h"

size_t			map_size(const char *file, t_map *map)
{
	int		fd;
	char	*str;
	int		width;

	width = 0;
	map->height = 0;
	fd = open(file, O_RDONLY);
	while(get_next_line(fd, &str))
	{
		width = count_of_words(str, ' ');
		if (map->height == 0)
			map->width = width;
		else if (map->width != width)
			print_error(ERR_MAP_INVAL);
		map->height++;
		ft_strdel(&str);
	}
	close(fd);
	return (sizeof(int) * (map->height * map->width));
}

t_map		*map_init(const char *file)
{
	t_map	*map;
	size_t	size;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		print_error(ERR_MAP_INIT);
	size = map_size(file, map);
	if (!(map->coords = (int *)malloc(size)))
		print_error(ERR_MAP_INIT);
	if (!(map->colors = (int *)malloc(size)))
		print_error(ERR_MAP_INIT);
	map->z_min = MAX_INT;
	map->z_max = MIN_INT;
	return (map);
}

void			parse_data(char **coords, t_map *map)
{
	static int	i = 0;
	char		**parts;

	while (*coords)
	{
		if (!(parts = ft_strsplit(*(coords++), ',')))
			print_error(ERR_MAP_READ);
		if (!ft_isnumber_base(parts[0], 10))
			print_error(ERR_MAP_INVAL);
		if (parts[1] && !ft_isnumber_base(parts[1], 16))
			print_error(ERR_MAP_INVAL);
		map->coords[i] = ft_atoi(parts[0]);
		map->colors[i++] = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	 	free_words(&parts);
	}
}

int			read_map(const char *file, t_map *map)
{
	int		fd;
	char	*line;
	char	**coords;
	int		result;

	fd = open(file, O_RDONLY);
	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(coords = ft_strsplit(line, ' ')))
			print_error(ERR_MAP_READ);
		parse_data(coords, map);
		free_words(&coords);
		ft_strdel(&line);
	}
	if (!map->coords)
		print_error(ERR_MAP_INVAL);
	close(fd);
	return (result);
}


/*
** TODO: rewrite ft_strsplit for readind from GNL for 2d array,
**       before it count rows - it will 2d array of t_point
*/