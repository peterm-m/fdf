/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:06:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/13 20:16:55 by pedromar         ###   ########.fr       */
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
	set_control(render);
	mlx_loop(win.mlx);
	exit(EXIT_SUCCESS);
}
