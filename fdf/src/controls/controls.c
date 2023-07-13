/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:18:44 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/13 21:26:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_control(t_render *r)
{
	mlx_hook(r->img->win.win, 2, 1L << 0, &key_manager, r);
	mlx_hook(r->img->win.win, 3, 1L << 0L, &key_manager, r);
	mlx_hook(r->img->win.win, 4, 1L << 2, &mouse_button_manager, r);
	mlx_hook(r->img->win.win, 5, 1L << 3, &mouse_button_release, r);
	mlx_hook(r->img->win.win, 6, 1L << 6, &mouse_motion_manager, r);
	mlx_hook(r->img->win.win, 17, 0L, &ft_end_program, r);
	mlx_loop_hook(r->img->win.mlx, &ft_plot_map, r);
}
