/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:20:24 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/05/20 18:20:31 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "interface.h"
#include "libft.h"

int			main(int ac, char **av)
{
	t_map	*map;
	t_fdf	*fdf;

	errno = 0;
	if (ac == 2)
	{
		map = map_init(av[1]);
		if (read_map(av[1], map) == -1)
			print_error(ERR_MAP_READ);
		fdf = fdf_init(map);
		fdf->camera = camera_init(fdf);
		print_map(map, fdf);
		setup_control(fdf);
		mlx_loop(fdf->mlx);
	}
	print_error(ERR_USAGE);
	return (0);
}
