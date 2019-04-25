#include "../inc/fdf.h"
#include "../inc/color.h"

static double	percentage(int start, int end, int current)
{
	double		placement;
	double		distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int				get_color(t_point current, t_point a, t_point b, t_point delta)
{
	int			rgb[3];
	double		percent;

	if (current.color == b.color)
		return (current.color);
	if (delta.x > delta.y)
		percent = percentage(a.x, b.x, current.x);
	else
		percent = percentage(a.y, b.y, current.y);
	rgb[0] = LIGHT(GET_RED(a.color), GET_RED(b.color), percent);
	rgb[1] = LIGHT(GET_GREEN(a.color), GET_GREEN(b.color), percent);
	rgb[2] = LIGHT(GET_BLUE(a.color), GET_BLUE(b.color), percent);
	return(UNION_RGB(rgb));
}

void			set_default_colors(t_map *map)
{
	int			i;
	int			rgb[3];
	double		percent;

	i = 0;
	while (i < map->height * map->width)
	{
		if (map->points[i].color == -1)
		{
			percent = percentage(map->z_min, map->z_max, map->points[i].z);
			rgb[0] = LIGHT(GET_RED(GREEN_COLOR), GET_RED(BLUE_COLOR), percent);
			rgb[1] = LIGHT(GET_GREEN(GREEN_COLOR), GET_GREEN(BLUE_COLOR), percent);
			rgb[2] = LIGHT(GET_BLUE(GREEN_COLOR), GET_BLUE(BLUE_COLOR), percent);
			map->points[i++].color = UNION_RGB(rgb);
		}
	}
}