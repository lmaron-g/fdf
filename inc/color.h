#ifndef COLOR_H
# define COLOR_H

# define PURPLE_COLOR		0xBD93F9
# define GREEN_COLOR		0x50FA7B
# define BLUE_COLOR		    0x8BE9FD
# define YELLOW_COLOR		0xFFB86C
# define TEXT_COLOR			0xF2F2F2
# define BACKGROUND			0x282A36
# define MENU_BACKGROUND	0x3C4556

# define COLOR_DISCO		0x9A1F6A
# define COLOR_BRICK_RED	0xC2294E
# define COLOR_FLAMINGO		0xEC4B27
# define COLOR_JAFFA		0xEF8633
# define COLOR_SAFFRON		0xF3AF3D

# define GET_RED(color)					((color >> 16) & 0xFF)
# define GET_GREEN(color)				((color >> 8) & 0xFF)
# define GET_BLUE(color)				(color & 0xFF)
# define UNION_RGB(rgb)					((rgb[0] << 16) | (rgb[1] << 8) | rgb[2])

# define LIGHT(a, b, per) ((int)((1 - per) * a + per * b))

void		set_default_colors(t_map *map);
int			get_color(t_point current, t_point a, t_point b, t_point delta);

#endif
