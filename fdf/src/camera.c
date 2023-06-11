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

void	set_transform_model(t_cam *c)
{
	float	x;
	float	y;
	float	z;

	x = (c->model).ang_x;
	y = - (c->model).ang_y;
	z = (c->model).ang_z;
	ft_setrow4(&(c->model).model, (t_vec4){cosf(y) * cosf(z),
		-cosf(y) * sinf(z), sinf(y), -(c->model).pos_mod.x}, 0);
	ft_setrow4(&(c->model).model, (t_vec4){sinf(x) * sinf(y) * cosf(z)
		+ cosf(x) * sinf(z), -sinf(x) * sinf(y) * sinf(z) + cosf(x) * cosf(z),
		- sinf(x) * cos(y), -(c->model).pos_mod.y}, 1);
	ft_setrow4(&(c->model).model, (t_vec4){-cosf(x) * sinf(y) * cosf(z)
		+ sinf(x) * sinf(z), cosf(x) * sinf(y) * sinf(z)
		+ sinf(x) * cosf(z), cosf(x) * cosf(y), -(c->model).pos_mod.z}, 2);
	ft_setrow4(&(c->model).model, (t_vec4){0, 0, 0, 1}, 3);
}

void	set_transform_view(t_cam *c)
{
	t_vec3	forward;
	t_vec3	left;
	t_vec3	up;
	t_vec3	tras;

	forward = ft_normalize3(ft_minus3((c->view).pos_cam,
				(c->view).target));
	left = ft_normalize3(ft_vector_product3(&(c->view).up, &forward));
	up = ft_vector_product3(&forward, &left);
	ft_setrow4(&(c->view).view, (t_vec4){left.x, left.y, left.z, 0}, 0);
	ft_setrow4(&(c->view).view, (t_vec4){forward.x,
		forward.y, forward.z, 0}, 2);
	ft_setrow4(&(c->view).view, (t_vec4){up.x, up.y, up.z, 0}, 1);
	ft_setrow4(&(c->view).view, (t_vec4){0, 0, 0, 1}, 3);
	tras.x = -1 * ft_dot_product3(left, (c->view).pos_cam);
	tras.y = -1 * ft_dot_product3(up, (c->view).pos_cam);
	tras.z = -1 * ft_dot_product3(forward, (c->view).pos_cam);
	ft_setcol4(&(c->view).view, (t_vec4){tras.x, tras.y, tras.z, 1}, 3);
}

void	set_transform_proj(t_cam *c)
{
	if ((c->proj).type == PROJECTION)
		projection(c);
	else if ((c->proj).type == PROJEC_SYMMETRIC)
		sym_projection(c);
	else if ((c->proj).type == ORTHOGRAPHIC)
		orthographic(c);
	else if ((c->proj).type == ORTHO_SYMMETRIC)
		sym_orthographic(c);
}

void	set_transform(t_cam *c)
{
	t_matrix4	res;

	ft_matmul4(&res, &(c->model).model, &(c->view).view);
	ft_matmul4(&(c->trasform), &res, &(c->proj).proj);
}
