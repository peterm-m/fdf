/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:03:56 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/04 19:22:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam2	*ft_newcam2(void )
{
	t_cam2	*cam;

	cam = (t_cam2 *) malloc(sizeof(t_cam2));
}

void	set_transform_model(t_cam2 *c)
{
	float	x;
	float	y;
	float	z;

	x = (c->model).ang_x;
	y = - (c->model).ang_y;
	z = (c->model).ang_z;
	ft_tsetrow((c->model).model, (t_vec4){fcos(y) * cosf(z), -fcos(y) * sinf(z),
		sinf(y), 0}, 0);
	ft_tsetrow((c->model).model, (t_vec4){sinf(x) * sinf(y) * cosf(z)
		+ cosf(x) * sinf(z), -sinf(x) * sinf(y) * sinf(z) + cosf(x) * cosf(z),
		- sinf(x) * cos(y), 0}, 1);
	ft_tsetrow((c->model).model, (t_vec4){-cosf(x) * sinf(y) * cosf(z)
		+ sinf(x) * sinf(z), cosf(x) * sinf(y) * sinf(z)
		+ sinf(x) * cosf(z), cosf(x) * cosf(y), 0}, 2);
	ft_tsetcol((c->model).model, (t_vec4){(c->model).pos_mod.x,
		(c->model).pos_mod.y, (c->model).pos_mod.z, 1}, 3);
}

void	set_transform_view(t_cam2 *c)
{
	t_vec3	forward;
	t_vec3	left;
	t_vec3	up;
	t_vec3	tras;

	forward = ft_normalize(ft_traslation((c->view).pos_cam,
				(c->view).target));
	left = ft_normalize(ft_vector_product(&(c->view).up, &forward));
	up = ft_vector_product(&forward, &left);
	ft_tsetrow(&(c->view).view, (t_vec4){left.x, left.y, left.z, 0}, 0);
	ft_tsetrow(&(c->view).view, (t_vec4){forward.x,
		forward.y, forward.z, 0}, 2);
	ft_tsetrow(&(c->view).view, (t_vec4){up.x, up.y, up.z, 0}, 1);
	tras.x = -1 * ft_dot_product(left, (c->view).pos_cam);
	tras.y = -1 * ft_dot_product(up, (c->view).pos_cam);
	tras.z = -1 * ft_dot_product(forward, (c->view).pos_cam);
	ft_tsetcol(&(c->view).view, (t_vec4){tras.x, tras.y, tras.z, 1}, 3);
}

void	projection(float rx[2], float ry[2], float rz[2], t_proj *p)
{
	return ;
}

void	sym_projection(float rx[2], float ry[2], float rz[2], t_proj *p)
{
	return ;
}

void	orthographic(float rx[2], float ry[2], float rz[2], t_proj *p)
{
	return ;
}

void	sym_orthographic(float rx[2], float ry[2], float rz[2], t_proj *p)
{
	return ;
}
