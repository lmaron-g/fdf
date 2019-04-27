#include "mlx.h"
#include "fdf.h"
#include "color.h"
#include "interface.h"
#include "libft.h"

static void	controls_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 15, 20, YELLOW_COLOR, "CONTROLS");
	mlx_string_put(fdf->mlx, fdf->win, 15, 55, TEXT_COLOR, "Move:");
	mlx_string_put(fdf->mlx, fdf->win, 85, 55, PINK_COLOR, "Arrows");
	mlx_string_put(fdf->mlx, fdf->win, 155, 55, TEXT_COLOR, "|");
	mlx_string_put(fdf->mlx, fdf->win, 175, 45, PINK_COLOR, "  W");
	mlx_string_put(fdf->mlx, fdf->win, 175, 65, PINK_COLOR, "A S D");
	mlx_string_put(fdf->mlx, fdf->win, 15, 95, TEXT_COLOR, "Zoom:");
	mlx_string_put(fdf->mlx, fdf->win, 85, 95, PINK_COLOR, "Scroll");
	mlx_string_put(fdf->mlx, fdf->win, 155, 92, TEXT_COLOR, "|");
	mlx_string_put(fdf->mlx, fdf->win, 175, 95, PINK_COLOR, "+/-");
	mlx_string_put(fdf->mlx, fdf->win, 15, 135, TEXT_COLOR, "Scale Z:");
	mlx_string_put(fdf->mlx, fdf->win, 135, 135, PINK_COLOR, "<");
	mlx_string_put(fdf->mlx, fdf->win, 155, 132, TEXT_COLOR, "|");
	mlx_string_put(fdf->mlx, fdf->win, 175, 135, PINK_COLOR, ">");
	mlx_string_put(fdf->mlx, fdf->win, 15, 210, TEXT_COLOR, "Rotate:");
	mlx_string_put(fdf->mlx, fdf->win, 105, 170, PINK_COLOR, " U   I   O ");
	mlx_string_put(fdf->mlx, fdf->win, 105, 190, TEXT_COLOR, " +   +   + ");
	mlx_string_put(fdf->mlx, fdf->win, 105, 210, PINK_COLOR, "[X] [Y] [Z]");	
	mlx_string_put(fdf->mlx, fdf->win, 105, 230, TEXT_COLOR, " -   -   - ");
	mlx_string_put(fdf->mlx, fdf->win, 105, 255, PINK_COLOR, " J   K   L ");
}

static void	projection_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 15, 325, YELLOW_COLOR, "PROJECTION");
	mlx_string_put(fdf->mlx, fdf->win, 15, 360, TEXT_COLOR, "Horizontal:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 360, PINK_COLOR, "1");
	mlx_string_put(fdf->mlx, fdf->win, 15, 390, TEXT_COLOR, "FRONT:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 390, PINK_COLOR, "2");
	mlx_string_put(fdf->mlx, fdf->win, 15, 420, TEXT_COLOR, "CROSS:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 420, PINK_COLOR, "3");
	mlx_string_put(fdf->mlx, fdf->win, 15, 450, TEXT_COLOR, "ISO:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 450, PINK_COLOR, "4");
}

static void	info_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 15, 535, YELLOW_COLOR, "INFORMATION");
	mlx_string_put(fdf->mlx, fdf->win, 15, 570, TEXT_COLOR, "Width:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 570, PINK_COLOR, ft_itoa(fdf->map->width));
	mlx_string_put(fdf->mlx, fdf->win, 15, 600, TEXT_COLOR, "Height:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 600, PINK_COLOR, ft_itoa(fdf->map->height));
	mlx_string_put(fdf->mlx, fdf->win, 15, 630, TEXT_COLOR, "Zoom:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 630, PINK_COLOR, ft_itoa(fdf->camera->zoom));
	mlx_string_put(fdf->mlx, fdf->win, 15, 660, TEXT_COLOR, "Alfa:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 660, PINK_COLOR, ft_ftoa(fdf->camera->alpha, 3));
	mlx_string_put(fdf->mlx, fdf->win, 15, 690, TEXT_COLOR, "Beta:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 690, PINK_COLOR, ft_ftoa(fdf->camera->beta, 3));
	mlx_string_put(fdf->mlx, fdf->win, 15, 720, TEXT_COLOR, "Gamma:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 720, PINK_COLOR, ft_ftoa(fdf->camera->gamma, 3));
	mlx_string_put(fdf->mlx, fdf->win, 15, 750, TEXT_COLOR, "Scale Z:");
	mlx_string_put(fdf->mlx, fdf->win, 155, 750, PINK_COLOR, 
									ft_ftoa(fdf->camera->zoom / fdf->camera->z_divider, 3));
}

void		setup_menu(t_fdf *fdf)
{
	controls_menu(fdf);
	projection_menu(fdf);
	info_menu(fdf);
}