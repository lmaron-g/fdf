/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:18:31 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/05/20 18:18:45 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "interface.h"
#include "libft.h"

t_camera		*camera_init(t_fdf *fdf)
{
	t_camera	*camera;

	if (!(camera = (t_camera *)ft_memalloc(sizeof(t_camera))))
		print_error(ERR_CAMERA_INIT);
	camera->zoom = DEF_ZOOM(fdf);
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->z_divider = 1;
	camera->x_offset = 0;
	camera->y_offset = -30;
	camera->projection = ISO;
	return (camera);
}
