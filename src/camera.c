#include "../inc/fdf.h"
#include "../inc/interface.h"
#include "../libft/includes/libft.h"

t_camera	*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		print_error(ERR_CAMERA_INIT);
	camera->zoom = FT_MIN((WIDTH - MENU_WIDTH) / fdf->map->width / 2,
												HEIGHT / fdf->map->height / 2);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divisor = 1;
	camera->x_offset = 0;
	camera->y_offset = 0;
	return (camera);
}