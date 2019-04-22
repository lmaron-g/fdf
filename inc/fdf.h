#ifndef FDF_H
# define FDF_H

#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../libft/includes/libft.h"

# define WIDTH				1800
# define HEIGHT				1800

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP_FILE		"Incorrect MAP_FILE"
# define ERR_MAP_READ		"Error: reading MAP_FILE"
# define ERR_MAP_INVAL		"Invalid MAP_FILE"
# define ERR_MAP_INIT		"Initialization error: MAP"
# define ERR_SPLIT			"Error: split map"
# define ERR_FDF_INIT		"Error: init fdf"

typedef struct          s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct          s_coord
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_coord;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_fdf;

typedef struct			s_map
{
	int					width;
	int					height;
	int					z_min;
	int					z_max;
	int					*coords;
	int					*colors;
}						t_map;

t_map		*map_init(const char *file);
int			read_map(const char *file, t_map *map);
void		count_points(const char *file, t_map *map);
t_map		*map_init(const char *file);

#endif