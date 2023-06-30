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
	set_transform_model(c);
	printf("model\n");
	print_matrix4(c->model);
	set_transform_view(c);
	printf("view\n");
	print_matrix4(c->view);
	set_transform_proj(c);
	printf("proj\n");
	print_matrix4(c->proj);
	ft_matmul4(c->trasform, *(c->trasform), *(c->model));
	ft_matmul4(c->trasform, *(c->trasform), *(c->view));
	ft_matmul4(c->trasform, *(c->trasform), *(c->proj));
	printf("total\n");
	print_matrix4(c->trasform);
}

void	set_transform_model(t_cam *c)
{
	t_matrix4	rot;

	traslation(&(c->pos_model), c->model);
	axis_rotation(c->rot_model.x, &((t_vec3){1, 0, 0}), &rot);
	ft_matmul4(c->model, *(c->model), rot);
	axis_rotation(c->rot_model.y, &((t_vec3){0, 1, 0}), &rot);
	ft_matmul4(c->model, *(c->model), rot);
	axis_rotation(c->rot_model.z, &((t_vec3){0, 0, 1}), &rot);
	ft_matmul4(c->model, *(c->model), rot);
}

void	set_transform_view(t_cam *c)
{
	t_matrix4	rot;

	axis_rotation(c->rot_view.x, &((t_vec3){0, 0, 1}), &rot);
	ft_matmul4(c->view, *(c->view), rot);
	axis_rotation(-c->rot_view.y, &((t_vec3){0, 1, 0}), &rot);
	ft_matmul4(c->view, *(c->view), rot);
	axis_rotation(c->rot_view.z, &((t_vec3){1, 0, 0}), &rot);
	ft_matmul4(c->view, *(c->view), rot);
	traslation(&((t_vec3){
			-c->pos_view.x,
			-c->pos_view.y,
			-c->pos_view.z}), &rot);
	ft_matmul4(c->view, *(c->view), rot);
}

void	set_transform_proj(t_cam *c)
{
	if (c->proj_type == PROJECTION)
		projection(c);
	else if (c->proj_type == PROJEC_SYMMETRIC)
		sym_projection(c);
	else if (c->proj_type == ORTHOGRAPHIC)
		orthographic(c);
	else if (c->proj_type == ORTHO_SYMMETRIC)
		sym_orthographic(c);
}
