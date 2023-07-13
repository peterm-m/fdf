/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:24:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/13 21:06:09 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_manager(int key, t_render *r)
{
	ft_bzero((void *)(r->img->addr), r->img->h * r->img->size_line
		+ r->img->w * (r->img->bpp / 8));
	if (key == KEY_ESC)
		ft_end_program(r);
	else if (key == KEY_R)
		default_camera(r->cam);
	view_manager(key, r);
	model_manger(key, r);
	projection_manager(key, r);
	set_transform(r->cam);
	return (EXIT_SUCCESS);
}

void	view_manager(int key, t_render *r)
{
	r->cam->pos_view.z -= 1 * (key == KEY_Q);
	r->cam->pos_view.z += 1 * (key == KEY_E);
	r->cam->pos_view.y -= 1 * (key == KEY_W);
	r->cam->pos_view.y += 1 * (key == KEY_S);
	r->cam->pos_view.x -= 1 * (key == KEY_A);
	r->cam->pos_view.x += 1 * (key == KEY_D);
	r->cam->rot_view.z -= 0.1 * (key == KEY_U);
	r->cam->rot_view.z += 0.1 * (key == KEY_O);
	r->cam->rot_view.y -= 0.1 * (key == KEY_I);
	r->cam->rot_view.y += 0.1 * (key == KEY_K);
	r->cam->rot_view.x -= 0.1 * (key == KEY_J);
	r->cam->rot_view.x += 0.1 * (key == KEY_L);
}

void	model_manger(int key, t_render *r)
{
	r->cam->pos_model.z += 1 * (0 * key);
	r->cam->pos_model.z -= 1 * (0 * key);
	r->cam->pos_model.y += 1 * (0 * key);
	r->cam->pos_model.y -= 1 * (0 * key);
	r->cam->pos_model.x += 1 * (0 * key);
	r->cam->pos_model.x -= 1 * (0 * key);
	r->cam->rot_model.z += 0.1 * (0 * key);
	r->cam->rot_model.z -= 0.1 * (0 * key);
	r->cam->rot_model.y += 0.1 * (0 * key);
	r->cam->rot_model.y -= 0.1 * (0 * key);
	r->cam->rot_model.x += 0.1 * (0 * key);
	r->cam->rot_model.x -= 0.1 * (0 * key);
}

void	projection_manager(int key, t_render *r)
{
	r->cam->proj_max.z += 0.2 * (r->cam->proj_max.z < 5 && key == KEY_MINUS);
	r->cam->proj_max.z -= 0.2 * (r->cam->proj_max.z > 0.5 && key == KEY_PLUS);
	r->cam->proj_max.y += 0.2 * (r->cam->proj_max.y < 5 && key == KEY_MINUS);
	r->cam->proj_max.y -= 0.2 * (r->cam->proj_max.y > 0.5 && key == KEY_PLUS);
	r->cam->proj_max.x += 0.2 * (r->cam->proj_max.x < 5 && key == KEY_MINUS);
	r->cam->proj_max.x -= 0.2 * (r->cam->proj_max.x > 0.5 && key == KEY_PLUS);
	r->cam->proj_min.z += 0.2 * (r->cam->proj_min.z < -0.5 && key == KEY_PLUS);
	r->cam->proj_min.z -= 0.2 * (r->cam->proj_min.z > -5 && key == KEY_MINUS);
	r->cam->proj_min.y += 0.2 * (r->cam->proj_min.y < -0.5 && key == KEY_PLUS);
	r->cam->proj_min.y -= 0.2 * (r->cam->proj_min.y > -5 && key == KEY_MINUS);
	r->cam->proj_min.x += 0.2 * (r->cam->proj_min.x < -0.5 && key == KEY_PLUS);
	r->cam->proj_min.x -= 0.2 * (r->cam->proj_min.x > -5 && key == KEY_MINUS);
}
