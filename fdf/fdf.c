/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:06:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/13 15:09:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_manager(int key, void *param)
{
	t_img	*img;

	img = (t_img *) param;
	if (key == F_ESC)
		ft_end(&img->win);
	return (EXIT_SUCCESS);
}

static int	mouse_manager(int buttom, int x, int y, void *param)
{
	t_img	*img;

	img = (t_img *) param;
	printf("bu %d, x %d, y %d \n", buttom, x, y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	win;
	t_img	img;
	t_map	*map;

	if (argc != 2)
		return (EXIT_FAILURE);
	win = ft_program(DEFAULT_WINSIZX, DEFAULT_WINSIZY, "fdf");
	img = ft_image(win, DEFAULT_IMGSIZX, DEFAULT_IMGSIZY);
	map = ft_parser(argv[1]);
	mlx_hook(win.win, 17, 1L << 0, ft_end, &win);
	mlx_key_hook(win.win, key_manager, &win);
	mlx_mouse_hook(win.win, mouse_manager, &win);
	mlx_put_image_to_window(win.mlx, win.win, img.ptr, 0, 0);
	mlx_loop(win.mlx);
	exit(EXIT_SUCCESS);
}
