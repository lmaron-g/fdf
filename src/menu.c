/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:34:37 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/05/20 18:34:40 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "color.h"
#include "interface.h"
#include "libft.h"

void	output(t_fdf *fdf, int x, int y, char **s)
{
	STR(x, y, PINK_COLOR, *s);
	ft_strdel(s);
}

static void	controls_menu(t_fdf *fdf)
{
	STR(15, 20, YELLOW_COLOR, "CONTROLS");
	STR(15, 55, TEXT_COLOR, "Move:");
	STR(85, 55, PINK_COLOR, "Arrows");
	STR(155, 55, TEXT_COLOR, "|");
	STR(175, 45, PINK_COLOR, "  W");
	STR(175, 65, PINK_COLOR, "A S D");
	STR(15, 95, TEXT_COLOR, "Zoom:");
	STR(85, 95, PINK_COLOR, "Scroll");
	STR(155, 92, TEXT_COLOR, "|");
	STR(175, 95, PINK_COLOR, "+/-");
	STR(15, 135, TEXT_COLOR, "Scale Z:");
	STR(135, 135, PINK_COLOR, "<");
	STR(155, 132, TEXT_COLOR, "|");
	STR(175, 135, PINK_COLOR, ">");
	STR(15, 210, TEXT_COLOR, "Rotate:");
	STR(105, 170, PINK_COLOR, " U   I   O ");
	STR(105, 190, TEXT_COLOR, " +   +   + ");
	STR(105, 210, PINK_COLOR, "[X] [Y] [Z]");	
	STR(105, 230, TEXT_COLOR, " -   -   - ");
	STR(105, 255, PINK_COLOR, " J   K   L ");
}

static void	projection_menu(t_fdf *fdf)
{
	STR(15, 325, YELLOW_COLOR, "PROJECTION");
	STR(15, 360, TEXT_COLOR, "Horizontal:");
	STR(155, 360, PINK_COLOR, "1");
	STR(15, 390, TEXT_COLOR, "FRONT:");
	STR(155, 390, PINK_COLOR, "2");
	STR(15, 420, TEXT_COLOR, "CROSS:");
	STR(155, 420, PINK_COLOR, "3");
	STR(15, 450, TEXT_COLOR, "ISO:");
	STR(155, 450, PINK_COLOR, "4");
}

static void	info_menu(t_fdf *fdf)
{
	char	*out;

	STR(15, 535, YELLOW_COLOR, "INFORMATION");
	STR(15, 570, TEXT_COLOR, "Width:");
	out = ft_itoa(fdf->map->width);
	output(fdf, 155, 570, &out);
	STR(15, 600, TEXT_COLOR, "Height:");
	out = ft_itoa(fdf->map->height);
	output(fdf, 155, 600, &out);
	STR(15, 630, TEXT_COLOR, "Zoom:");
	out = ft_itoa(fdf->camera->zoom);
	output(fdf, 155, 630, &out);
	STR(15, 660, TEXT_COLOR, "Alfa:");
	out = ft_ftoa(fdf->camera->alpha, 3);
	output(fdf, 155, 660, &out);
	STR(15, 690, TEXT_COLOR, "Beta:");
	out = ft_ftoa(fdf->camera->beta, 3);
	output(fdf, 155, 690, &out);
	STR(15, 720, TEXT_COLOR, "Gamma:");
	out = ft_ftoa(fdf->camera->gamma, 3);
	output(fdf, 155, 720, &out);
	STR(15, 750, TEXT_COLOR, "Scale Z:");
	out = ft_ftoa(fdf->camera->zoom / fdf->camera->z_divider, 3);
	output(fdf, 155, 750, &out);
}

void		setup_menu(t_fdf *fdf)
{
	controls_menu(fdf);
	projection_menu(fdf);
	info_menu(fdf);
}
