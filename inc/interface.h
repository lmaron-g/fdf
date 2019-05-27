/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:26:42 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/05/20 19:26:45 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERFACE_H
# define INTERFACE_H

# define WIDTH				1440
# define HEIGHT				810
# define MENU_WIDTH			250
# define ZOOM_WIDTH			(WIDTH - MENU_WIDTH) / fdf->map->width / 2
# define ZOOM_HEIGHT		HEIGHT / fdf->map->height / 2

# define STR(x, y, c, s)	(mlx_string_put(fdf->mlx, fdf->win, x, y, c, s))

# define FT_MIN(a, b)		(((a) < (b)) ? (a) : (b))
# define DEF_ZOOM(fdf)		FT_MIN(ZOOM_WIDTH, ZOOM_HEIGHT)

void						setup_menu(t_fdf *fdf);
void						setup_background(t_fdf *fdf);

void						setup_control(t_fdf *fdf);

int							key_press(int key, void *param);
int							mouse_press(int button, int x, int y, void *param);
int							mouse_release(int but, int x, int y, void *param);
int							mouse_move(int x, int y, void *param);
int							close_win(void *param);

void						zoom(int key, t_fdf *fdf);
void						move(int key, t_fdf *fdf);
void						rotate(int key, t_fdf *fdf);
void						scale(int key, t_fdf *fdf);
void						change_projection(int key, t_fdf *fdf);

#endif
