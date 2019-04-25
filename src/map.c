#include <fcntl.h>
#include "../inc/fdf.h"
#include "../inc/color.h"
#include "../libft/includes/libft.h"

static size_t	map_size(const char *file, t_map *map)
{
	int			fd;
	char		*str;
	int			width;

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
	map->size = map->height * map->width;
	return (sizeof(t_point) * map->size);
}

t_map			*map_init(const char *file)
{
	t_map		*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		print_error(ERR_MAP_INIT);
	if (!(map->points = (t_point *)ft_memalloc(map_size(file, map))))
		print_error(ERR_MAP_INIT);
	map->z_min = MAX_INT;
	map->z_max = MIN_INT;
	return (map);
}

static void		parse_data(char **coords, t_map *map)
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
		map->points[i].x = i % map->width;
		map->points[i].y = i / map->width;
		map->points[i].z = ft_atoi(parts[0]);
		if (map->points[i].z > map->z_max)
			map->z_max = map->points[i].z;
		if (map->points[i].z < map->z_min)
			map->z_min = map->points[i].z;
		map->points[i++].color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
		free_words(&parts);
	}
}

int				read_map(const char *file, t_map *map)
{
	int			fd;
	char		*line;
	char		**coords;
	int			result;

	fd = open(file, O_RDONLY);
	while ((result = get_next_line(fd, &line)) == 1)
	{
		if (!(coords = ft_strsplit(line, ' ')))
			print_error(ERR_MAP_READ);
		parse_data(coords, map);
		free_words(&coords);
		ft_strdel(&line);
	}
	set_default_colors(map);
	if (!map->points)
		print_error(ERR_MAP_INVAL);
	close(fd);
	return (result);
}
