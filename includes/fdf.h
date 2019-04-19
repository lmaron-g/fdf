#ifndef FDF_H
# define FDF_H

#include "../minilibx/mlx.h"

# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP_FILE		"Incorrect MAP_FILE"
# define ERR_MAP_INIT		"Initialization error: MAP"
# define ERR_SPLIT          "Error: split map"

typedef struct          s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_map
{
	int					width;
	int					height;
	int					*coords_arr;
	int					*colors_arr;
	int					z_min;
	int					z_max;
	int					z_range;
}						t_map;

#endif