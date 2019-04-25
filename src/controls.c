#include <stdlib.h>
#include "../inc/fdf.h"
#include "../mlx/mlx.h"
#include "../inc/keys.h"
#include "../inc/interface.h"

/*
** TODO: Add: wasd jkl uio
*/

int			key_press(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, fdf);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, fdf);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_3 || key == MAIN_PAD_3
		|| key == NUM_PAD_4 || key == MAIN_PAD_4
		|| key == NUM_PAD_6 || key == MAIN_PAD_6
		|| key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_8 || key == MAIN_PAD_8
		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		rotate(key, fdf);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		scale(key, fdf);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, fdf);
	return (0);
}

int			mouse_press(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		zoom(button, fdf);
	else if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse->is_pressed = true;
	return (0);
}

int			mouse_release(int button, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->mouse->is_pressed = false;
	return (0);
}

int			mouse_move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	fdf->mouse->previous_x = fdf->mouse->x;
	fdf->mouse->previous_y = fdf->mouse->y;
	fdf->mouse->x = x;
	fdf->mouse->y = y;
	if (fdf->mouse->is_pressed)
	{
		fdf->camera->beta += (x - fdf->mouse->previous_x) * 0.002;
		fdf->camera->alpha += (y - fdf->mouse->previous_y) * 0.002;
		print_map(fdf->map, fdf);
	}
	return (0);
}

int		close_win(void *param)
{
	(void)param;
	exit(0);
	return (0);
}