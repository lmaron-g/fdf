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
	double		percent;

	if (current.color == b.color)
		return (current.color);
	if (delta.x > delta.y)
		percent = percentage(a.x, b.x, current.x);
	else
		percent = percentage(a.y, b.y, current.y);
	return(MERGE_RGB(NEW_LIGHT(GET_RED(a.color), GET_RED(b.color), percent),
					NEW_LIGHT(GET_GREEN(a.color), GET_GREEN(b.color), percent),
					NEW_LIGHT(GET_BLUE(a.color), GET_BLUE(b.color), percent)));
}

void			set_default_colors(t_map *map)
{
	int			i;
	double		percent;

	i = 0;
	while (i < map->size)
	{
		if (map->points[i].color == -1)
		{
			percent = percentage(map->z_min, map->z_max, map->points[i].z);
			map->points[i].color =
				MERGE_RGB(NEW_LIGHT(GET_RED(LOW_COLOR), GET_RED(HIGH_COLOR), percent),
						NEW_LIGHT(GET_GREEN(LOW_COLOR), GET_GREEN(HIGH_COLOR), percent),
						NEW_LIGHT(GET_BLUE(LOW_COLOR), GET_BLUE(HIGH_COLOR), percent));
		}
		i++;
	}
}