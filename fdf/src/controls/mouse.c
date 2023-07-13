/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:26:58 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/13 21:22:26 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_motion_manager(int x, int y, t_render *r)
{
	ft_bzero((void *)(r->img->addr), r->img->h * r->img->size_line
		+ r->img->w * (r->img->bpp / 8));
	if (r->cam->button_press == MOUSE_LEFT)
		r->cam->rot_model = ft_vec3(
				fmod((float)y / 100, (2 * M_PI)),
				fmod((float)x / 100, (2 * M_PI)),
				r->cam->rot_model.z += r->cam->rot_model.z);
	else if (r->cam->button_press == MOUSE_CENTER)
		r->cam->rot_model = ft_vec3(
				r->cam->rot_model.x,
				r->cam->rot_model.y,
				fmod((float)y / 100, (2 * M_PI)));
	else if (r->cam->button_press == MOUSE_ROLL_UP)
		projection_manager(KEY_PLUS, r);
	else if (r->cam->button_press == MOUSE_ROLL_DOWN)
		projection_manager(KEY_MINUS, r);
	set_transform(r->cam);
	return (0);
}

int	mouse_button_manager(int buttom, int x, int y, t_render *r)
{
	x = x + 0;
	y = x + 0;
	if (buttom != 0)
		r->cam->button_press = buttom;
	return (buttom);
}

int	mouse_button_release(int buttom, int x, int y, t_render *r)
{
	x = x + 0;
	y = x + 0;
	r->cam->button_press = 0;
	return (buttom);
}
