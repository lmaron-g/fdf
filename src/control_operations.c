#include "fdf.h"
#include "keys.h"
#include "interface.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS ||
		key == MAIN_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		fdf->camera->zoom++;
	else if (key == NUM_PAD_MINUS ||
		key == MAIN_PAD_MINUS ||
		key == MOUSE_SCROLL_DOWN)
		fdf->camera->zoom--;
	else if (key == MAIN_PAD_0)
	{
		fdf->camera->zoom = DEF_ZOOM(fdf);
		fdf->camera->x_offset = 0;
		fdf->camera->y_offset = 0;
	}
	if (fdf->camera->zoom < 1)
		fdf->camera->zoom = 1;
	print_map(fdf->map, fdf);
}

void	move(int key, t_fdf *fdf)
{
	if (key == ARROW_LEFT || key == MAIN_PAD_D)
		fdf->camera->x_offset -= 10;
	else if (key == ARROW_RIGHT || key == MAIN_PAD_A)
		fdf->camera->x_offset += 10;
	else if (key == ARROW_UP || key == MAIN_PAD_S)
		fdf->camera->y_offset -= 10;
	else if (ARROW_DOWN || key == MAIN_PAD_W)
		fdf->camera->y_offset += 10;
	print_map(fdf->map, fdf);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_J)
		fdf->camera->alpha -= 0.05;
	else if (key == MAIN_PAD_U)
		fdf->camera->alpha += 0.05;
	else if (key == MAIN_PAD_K)
		fdf->camera->beta -= 0.05;
	else if (key == MAIN_PAD_I)
		fdf->camera->beta += 0.05;
	else if (key == MAIN_PAD_L)
		fdf->camera->gamma -= 0.05;
	else if (key == MAIN_PAD_O)
		fdf->camera->gamma += 0.05;
	print_map(fdf->map, fdf);
}

void	scale(int key, t_fdf *fdf)
{
	if (key == MAIN_PAD_LESS)
		fdf->camera->z_divider /= 1.1;
	else if (key == MAIN_PAD_MORE)
		fdf->camera->z_divider *= 1.1;
	if (fdf->camera->z_divider < 0.1)
		fdf->camera->z_divider = 0.1;
	else if (fdf->camera->z_divider > fdf->camera->zoom)
		fdf->camera->z_divider = fdf->camera->zoom;
	print_map(fdf->map, fdf);
}

void	change_projection(int key, t_fdf *fdf)
{
	fdf->camera->alpha = 0;
	fdf->camera->beta = 0;
	fdf->camera->gamma = 0;
	if (key == MAIN_PAD_1)
		fdf->camera->projection = HORIZONTAL;
	else if (key == MAIN_PAD_2)
		fdf->camera->alpha = -1.570796;
	else if (key == MAIN_PAD_3)
	{
		fdf->camera->beta = -1.570796;
		fdf->camera->alpha = -1.570796;
	}
	else if (key == MAIN_PAD_4)
		fdf->camera->projection = ISO;
	print_map(fdf->map, fdf);
}