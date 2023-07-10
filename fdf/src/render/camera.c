/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:03:56 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/10 18:29:01 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_transform(t_cam *c)
{
	c->model = translate(c->pos_model);
	c->model = ft_mulm4m(rotater(c->rot_model.x,
				ft_vec3(1.0f, 0.0f, 0.0f)), c->model);
	c->model = ft_mulm4m(rotater(c->rot_model.y,
				ft_vec3(0.0f, 1.0f, 0.0f)), c->model);
	c->model = ft_mulm4m(rotater(c->rot_model.z,
				ft_vec3(0.0f, 0.0f, 1.0f)), c->model);
	c->view = rotater(c->rot_view.z, ft_vec3(0.1f, 0.0f, 0.0f));
	c->view = ft_mulm4m(rotater(-c->rot_view.y,
				ft_vec3(0.0f, 1.0f, 0.0f)), c->view);
	c->view = ft_mulm4m(rotater(c->rot_view.x,
				ft_vec3(0.0f, 0.0f, 1.0f)), c->view);
	c->view = ft_mulm4m(translate(c->pos_view), c->view);
	c->proj = orthographicr(c->proj_max, c->proj_min);
	c->trasform = ft_mulm4m(c->model, c->view);
	c->trasform = ft_mulm4m(c->proj, c->trasform);
	c->trasform = ft_mulm4m(c->trasform,
			scale(ft_vec3(10.0f, 10.0f, 10.0f)));
	c->trasform = ft_mulm4m(c->trasform,
			translate(ft_vec3(DEFAULT_WINX / 2, DEFAULT_WINY / 2, 0)));
}
