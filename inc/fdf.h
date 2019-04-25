#ifndef FDF_H
# define FDF_H

#include "math.h"
#include <fcntl.h>
#include "../mlx/mlx.h"
#include "../libft/includes/libft.h"


# define ERR_USAGE			"Usage: ./fdf MAP_FILE"
# define ERR_MAP_FILE		"Incorrect MAP_FILE"
# define ERR_MAP_READ		"Error: reading MAP_FILE"
# define ERR_MAP_INVAL		"Invalid MAP_FILE"
# define ERR_MAP_INIT		"Initialization error: MAP"
# define ERR_CAMERA_INIT	"Initialization error: MAP"
# define ERR_SPLIT			"Error: split map"
# define ERR_FDF_INIT		"Error: init fdf"

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct			s_map
{
	int					size;
	int					width;
	int					height;
	int					z_min;
	int					z_max;
	t_point				*points;
}						t_map;

typedef struct			s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct			s_camera
{
	t_projection		projection;
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_camera;

typedef struct			s_fdf
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_camera			*camera;
	t_map				*map;
	t_mouse				*mouse;
}						t_fdf;

t_fdf		*fdf_init(t_map *map);
t_map		*map_init(const char *file);
t_camera	*camera_init(t_fdf *fdf);

int			read_map(const char *file, t_map *map);

void		print_map(t_map *map, t_fdf *fdf);

t_point		projection(t_point point, t_fdf *fdf);

#endif