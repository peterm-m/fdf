/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:06:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/24 15:17:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_win		win;
	t_render	*render;

	if (argc != 2)
		return (EXIT_FAILURE);
	win = ft_program(DEFAULT_WINX, DEFAULT_WINY, "fdf");
	render = set_render(&win, argv[1]);
	mlx_mouse_hook(win.win, &mouse_manager, &win);
	mlx_key_hook(win.win, &key_manager, render);
	mlx_loop_hook(win.mlx, &ft_plot_map, render);
	mlx_hook(win.win, 17, 1L << 0, &ft_end_program, render);
	mlx_loop(win.mlx);
	exit(EXIT_SUCCESS);
}
