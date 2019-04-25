#include "../mlx/mlx.h"
#include "../inc/fdf.h"
#include "../inc/color.h"
#include "../inc/interface.h"

void	ft_bzero(void *s, size_t n);

void	setup_menu(t_fdf *fdf)
{
	int	y;

	y = 0;
	mlx_string_put(fdf->mlx, fdf->win, 80, y += 20, PURPLE_COLOR, "Usage");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 35, TEXT_COLOR, "Zoom: Scroll or +/-");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, TEXT_COLOR, "Move: Arrows");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, TEXT_COLOR, "Flatten: </>");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, TEXT_COLOR, "Rotate: Press & Move");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, TEXT_COLOR, "Rotate:");
	mlx_string_put(fdf->mlx, fdf->win, 57, y += 25, TEXT_COLOR, "X-Axis - 2/8");
	mlx_string_put(fdf->mlx, fdf->win, 57, y += 25, TEXT_COLOR, "Y-Axis - 4/6");
	mlx_string_put(fdf->mlx, fdf->win, 57, y += 25, TEXT_COLOR, "Z-Axis - 1(3)/7(9)");
	mlx_string_put(fdf->mlx, fdf->win, 15, y += 30, TEXT_COLOR, "Projection");
	mlx_string_put(fdf->mlx, fdf->win, 57, y += 25, TEXT_COLOR, "ISO: I Key");
	mlx_string_put(fdf->mlx, fdf->win, 57, y += 25, TEXT_COLOR, "Parallel: P Key");
}

void	setup_background(t_fdf *fdf)
{
	int	*image;
	int	i;

	ft_bzero(fdf->data_addr, WIDTH * HEIGHT * (fdf->bits_per_pixel / 8));
	image = (int *)(fdf->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = (i % WIDTH < MENU_WIDTH) ? MENU_BACKGROUND : BACKGROUND;
		i++;
	}
}

void	setup_control(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, close_win, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
}