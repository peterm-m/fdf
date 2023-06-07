/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:06:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/07 20:44:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_manager(int key, t_render *render)
{
	printf("%d\n", key);
	if (key == F_ESC)
		ft_end(render);
	else if (key == Q_ZPLUS || key == E_ZMIN || key == W_XPLUS || key == S_XMIN
		|| key == A_YPLUS || key == D_YMIN)
		key_traslation(key, render->cam);
	else if (key == U_APLUS || key == O_AMIN || key == I_BPLUS
		|| key == K_BMIN || key == J_CPLUS || key == L_CMIN
		|| key == ANG_RESTORE)
		key_rotation(key, render->cam);
	else if (key == F_FOCPLUS || key == G_FOCMIN || key == B_SCALEPLUS
		|| key == N_SCALEMIN || key == R_SHPLUS || key == T_SHMIN
		|| key == Z_OFFXPLUS || key == X_OFFXMIN || key == C_OFFYPLUS
		|| key == V_OFFYMIN)
		key_affin(key, render->cam);
	return (EXIT_SUCCESS);
}

static int	mouse_manager(int buttom, int x, int y, void *render)
{
	render = (void *)render;
	ft_printf("bu %d, x %d, y %d \n", buttom, x, y);
	return (0);
}

static t_render	*set_render(t_win win, char *file)
{
	t_render	*new;

	new = (t_render *)malloc(sizeof(t_render));
	if (!new)
		exit(EXIT_FAILURE);
	new->img = ft_image(win, DEFAULT_IMGSIZX, DEFAULT_IMGSIZY);
	new->cam = ft_newcam();
	ft_parser(file, &(new->map));
	return (new);
}

int	main(int argc, char **argv)
{
//	t_win		win;
//	t_render	*render;
//
//	if (argc != 2)
//		return (EXIT_FAILURE);
//	win = ft_program(DEFAULT_WINX, DEFAULT_WINY, "fdf");
//	render = set_render(win, argv[1]);
//	mlx_mouse_hook(win.win, &mouse_manager, &win);
//	mlx_key_hook(win.win, &key_manager, render);
//	mlx_loop_hook(win.mlx, &ft_plot_map, render);
//	mlx_hook(win.win, 17, 1L << 0, &ft_end, render);
//	mlx_loop(win.mlx);
//	exit(EXIT_SUCCESS);
	argv = (void *) argv;
	argc++;
	t_cam2 *c = ft_newcam2();

	printf("%f %f %f %f\n", (c->view).view[0][0], (c->view).view[0][1], (c->view).view[0][2],(c->view).view[0][3]);
	printf("%f %f %f %f\n", (c->view).view[1][0], (c->view).view[1][1], (c->view).view[1][2],(c->view).view[1][3]);
	printf("%f %f %f %f\n", (c->view).view[2][0], (c->view).view[2][1], (c->view).view[2][2],(c->view).view[2][3]);
	printf("%f %f %f %f\n", (c->view).view[3][0], (c->view).view[3][1], (c->view).view[3][2],(c->view).view[3][3]);
}
