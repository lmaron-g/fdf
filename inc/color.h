#ifndef COLOR_H
# define COLOR_H

# define PURPLE_COLOR		0xBD93F9
# define GREEN_COLOR		0x50FA7B
# define BLUE_COLOR		    0x8BE9FD
# define CYAN_COLOR		    0x6B75FF
# define YELLOW_COLOR		0xFFB86C
# define TEXT_COLOR			0xF2F2F2

# define HIGH_COLOR			BLUE_COLOR
# define LOW_COLOR			GREEN_COLOR
# define BACKGROUND			0x282A36
# define MENU_BACKGROUND	0x3C4556
 
# define GET_RED(color)		((color >> 16) & 0xFF)
# define GET_GREEN(color)	((color >> 8) & 0xFF)
# define GET_BLUE(color)	(color & 0xFF)
# define MERGE_RGB(r, g, b)	((r << 16) | (g << 8) | b)

# define NEW_LIGHT(a, b, per)	((int)((1 - per) * a + per * b))

void						set_default_colors(t_map *map);
int							get_color(t_point current, t_point a, t_point b, t_point delta);

#endif
