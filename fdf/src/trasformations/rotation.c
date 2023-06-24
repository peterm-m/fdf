/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 14:53:35 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/24 17:55:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	axis_rotation(float angle, t_vec3 *axis, t_matrix4 *mat)
{
	float	c;
	float	s;

	c = fcos(angle);
	s = fsin(angle);
	ft_setrow4(&mat, (t_vec4){(1 - c) * axis->x * axis->x + c,
		(1 - c) * axis->x * axis->y - s * axis->z,
		(1 - c) * axis->x * axis->z - s * axis->y, 0}, 0);
	ft_setrow4(&mat, (t_vec4){(1 - c) * axis->x * axis->y - s * axis->z,
		(1 - c) * axis->y * axis->y + c,
		(1 - c) * axis->y * axis->z - s * axis->x, 0}, 1);
	ft_setrow4(&mat, (t_vec4){(1 - c) * axis->x * axis->z - s * axis->y,
		(1 - c) * axis->y * axis->z - s * axis->x,
		(1 - c) * axis->z * axis->z + c, 0}, 2);
	ft_setrow4(&mat, (t_vec4){0, 0, 0, 1}, 3);
}

void	rotationx(float angle, t_matrix4 *mat)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_setrow4(&mat, (t_vec4){1, 0, 0, 0}, 0);
	ft_setrow4(&mat, (t_vec4){0, c, -s, 0}, 1);
	ft_setrow4(&mat, (t_vec4){0, s, c, 0}, 2);
	ft_setrow4(&mat, (t_vec4){0, 0, 0, 1}, 3);
}

void	rotationy(float angle, t_matrix4 *mat)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_setrow4(&mat, (t_vec4){c, 0, -s, 0}, 0);
	ft_setrow4(&mat, (t_vec4){0, 1, 0, 0}, 1);
	ft_setrow4(&mat, (t_vec4){s, 0, c, 0}, 2);
	ft_setrow4(&mat, (t_vec4){0, 0, 0, 1}, 3);
}

void	rotationz(float angle, t_matrix4 *mat)
{
	float	c;
	float	s;

	c = cosf(angle);
	s = sinf(angle);
	ft_setrow4(&mat, (t_vec4){c, -s, 0, 0}, 0);
	ft_setrow4(&mat, (t_vec4){s, c, 0, 0}, 1);
	ft_setrow4(&mat, (t_vec4){0, 0, 1, 0}, 2);
	ft_setrow4(&mat, (t_vec4){0, 0, 0, 1}, 3);
}

void	angle_to_axes(t_vec3 *a, t_matrix4 *mat)
{
	float	cx;
	float	cy;
	float	cz;

	cx = cosf(a->x);
	cy = cosf(a->y);
	cz = cosf(a->z);
	ft_setcol4(&mat, (t_vec4){cy * cz,
		(1 - cx * cx) * (1 - cy * cy) * cz + cx * (1 - cz * cz),
		-cx * (1 - cy * cy) * cz + (1 - cx * cx) * (1 - cz * cz), 0}, 0);
	ft_setcol4(&mat, (t_vec4){-cy * (1 - cz * cz),
		-(1 - cx * cx) * (1 - cy * cy) * (1 - cz * cz) + cx * cz,
		cx * (1 - cy * cy) * (1 - cz * cz) + (1 - cx * cx) * cz, 0}, 1);
	ft_setcol4(&mat, (t_vec4){(1 - cy * cy),
		-(1 - cx * cx) * cy,
		cx * cy, 0}, 2);
	ft_setcol4(&mat, (t_vec4){0, 0, 0, 1}, 3);
}