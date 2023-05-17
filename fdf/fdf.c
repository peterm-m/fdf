/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:06:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/15 20:18:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_manager(int key, void *param)
{
	t_img	*img;

	img = (t_img *) param;
	if (key == F_ESC)
		ft_end(&img->win);
	else if (key == Q_ZPLUS || key == E_ZMIN || key == W_XPLUS || key == S_XMIN
		|| key == A_YPLUS || key == D_YMIN)
		printf("traslation %d\n", key);//key_traslatio(key);
	else if (key == U_APLUS || key == O_AMIN || key == I_BPLUS || key == K_BMIN ||
	key == J_CPLUS || key == L_CMIN )
		printf("rotation %d \n", key); // key_rotation(key);
	else if (key == F_FOCPLUS || key == G_FOCMIN || key == B_SCALEPLUS ||
	key == N_SCALEMIN || key == R_SHPLUS || key == T_SHMIN ||
	key == Z_OFFXPLUS || X_OFFXMIN || key == C_OFFYPLUS || key == V_OFFYMIN)
		printf("affin %d\n", key); // ft_affin(key);
	else
		printf("nada\n");
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
	t_cam	cam;
	t_map	*map;

	if (argc != 2)
		return (EXIT_FAILURE);
	win = ft_program(DEFAULT_WINX, DEFAULT_WINY, "fdf");
	img = ft_image(win, DEFAULT_IMGSIZX, DEFAULT_IMGSIZY);
	cam = ft_newcam();
	ft_parser(argv[1], &map);
	mlx_hook(win.win, 17, 1L << 0, ft_end, &win);
	mlx_mouse_hook(win.win, mouse_manager, &win);
	mlx_key_hook(win.win, key_manager, &win);
	ft_plot_map(img, map, cam);
	mlx_put_image_to_window(win.mlx, win.win, img.ptr, 0, 0);
	mlx_loop(win.mlx);
	exit(EXIT_SUCCESS);
}
