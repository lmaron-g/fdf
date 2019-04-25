#ifndef INTERFACE_H
# define INTERFACE_H

# define WIDTH				1440
# define HEIGHT				810
# define MENU_WIDTH			250

void	setup_menu(t_fdf *fdf);
void	setup_background(t_fdf *fdf);

void	setup_control(t_fdf *fdf);
int		key_press(int key, void *param);
int		mouse_press(int button, int x, int y, void *param);
int		mouse_release(int button, int x, int y, void *param);
int		mouse_move(int x, int y, void *param);
int		close_win(void *param);

void	zoom(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	scale(int key, t_fdf *fdf);
void	change_projection(int key, t_fdf *fdf);

#endif