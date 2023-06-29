/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:46:32 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/29 20:21:33 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define EPSILON 0.001F

void	look_at(t_vec3 *eye, t_vec3 *target, t_vec3 *up_dir, t_matrix4 *mat)
{
	t_vec3	fward;
	t_vec3	left;
	t_vec3	up;
	t_vec3	traslation;

	fward = ft_normalize3(ft_minus3((t_vec3){eye->x, eye->y, eye->z},
				(t_vec3){target->x, target->y, target->z}));
	left = ft_normalize3(ft_vector_product3(up_dir, &fward));
	up = ft_vector_product3(&fward, &left);
	traslation = (t_vec3){-left.x * eye->x - left.y * eye->y - left.z * eye->z,
		-up.x * eye->x - up.y * eye->y - up.z * eye->z,
		-fward.x * eye->x - fward.y * eye->y - fward.z * eye->z};
	ft_setrow4(mat, (t_vec4){left.x, left.y, left.z, traslation.x}, 0);
	ft_setrow4(mat, (t_vec4){up.x, up.y, up.z, traslation.y}, 1);
	ft_setrow4(mat, (t_vec4){fward.x, fward.y, fward.z, traslation.z}, 2);
	ft_setrow4(mat, (t_vec4){0, 0, 0, 1}, 3);
}

t_vec3	lookat_angles(t_matrix4 *mat)
{
	float	pitch;
	float	yaw;
	float	roll;

	yaw = asinf((*mat)[0][2]);
	roll = atanf(-(*mat)[0][1] / (*mat)[0][0]);
	pitch = atan(-(*mat)[1][3] / (*mat)[2][3]);
	return ((t_vec3){pitch, yaw, roll});
}

void	look_at_axes1(t_vec3 *pos, t_vec3 *target, t_matrix4 *mat)
{
	t_vec3	aux;

	ft_setcol4(mat, ft_normalize4(
			ft_minus4((t_vec4){pos->x, pos->y, pos->z, 0},
				(t_vec4){target->x, target->y, target->z, 0})), 2);
	if (fabs((*mat)[0][2]) < EPSILON && fabs((*mat)[2][2]) < EPSILON)
	{
		if ((*mat)[1][2] > 0)
			ft_setcol4(mat, (t_vec4){0, 0, -1, 0}, 1);
		else
			ft_setcol4(mat, (t_vec4){0, 0, 1, 0}, 1);
	}
	else
		ft_setcol4(mat, (t_vec4){0, 1, 0, 0}, 1);
	aux = ft_normalize3(ft_vector_product3(
				&((t_vec3){(*mat)[0][1], (*mat)[1][1], (*mat)[2][1]}),
				&((t_vec3){(*mat)[0][2], (*mat)[1][2], (*mat)[2][2]})));
	ft_setcol4(mat, (t_vec4){aux.x, aux.y, aux.z, 0}, 0);
	aux = ft_vector_product3(
			&(t_vec3){(*mat)[0][2], (*mat)[1][2], (*mat)[2][2]},
			&(t_vec3){(*mat)[0][0], (*mat)[1][0], (*mat)[2][0]});
	ft_setcol4(mat, (t_vec4){aux.x, aux.y, aux.z, 0}, 1);
}
