#include "../inc/fdf.h"
#include "../mlx/mlx.h"
#include "../inc/color.h"
#include "../inc/interface.h"
#include "../libft/includes/libft.h"

static void		plot(t_point point, int color, t_fdf *fdf)
{
	int		i;

	if (MENU_WIDTH < point.x && point.x < WIDTH &&
					0 < point.y && point.y < HEIGHT)
	{
		i = (point.x * fdf->bits_per_pixel / 8) + (point.y * fdf->size_line);
		fdf->data_addr[i] = color;
		fdf->data_addr[++i] = color >> 8;
		fdf->data_addr[++i] = color >> 16;
	}
}

static void		line(t_point a, t_point b, t_fdf *fdf)
{
	t_point	delta;
	t_point	sign;
	int		error[2];
	t_point	current;

	delta.x = FT_ABS(b.x - a.x);
	delta.y = FT_ABS(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	error[0] = delta.x -delta.y;
	current = a;
	while (current.x != b.x || current.y != b.y)
	{
		plot(current, get_color(current, a, b, delta), fdf);
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			current.x += sign.x; 
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			current.y += sign.y;
		}
	}
}

void		print_map(t_map *map, t_fdf *fdf)
{
	int		i;

	i = 0;
	setup_background(fdf);
	while (i < map->width * map->height)
	{
		if ((i + 1) % map->width != 0)
			line(projection(map->points[i], fdf),
				projection(map->points[i + 1], fdf), fdf);
		if (i / map->width != map->height - 1)
			line(projection(map->points[i], fdf),
				projection(map->points[i + map->width], fdf), fdf);
		i++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	setup_menu(fdf);
}

/*
** TODO: 
*/