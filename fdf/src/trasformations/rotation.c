/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:38:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/07 19:49:59 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4	rotater(float a, t_vec3 axis)
{
	t_matrix4	m;
	float		s;
	float		c;
	float		cv;

	s = sinf(a);
	c = cosf(a);
	cv = 1.0f - c;
	m = ft_ident4();
	axis = ft_divv3f(axis, ft_lenv3(axis));
	m.elements[0][0] = (axis.x * axis.x * cv) + c;
	m.elements[0][1] = (axis.x * axis.y * cv) + (axis.z * s);
	m.elements[0][2] = (axis.x * axis.z * cv) - (axis.y * s);
	m.elements[1][0] = (axis.y * axis.x * cv) - (axis.z * s);
	m.elements[1][1] = (axis.y * axis.y * cv) + c;
	m.elements[1][2] = (axis.y * axis.z * cv) + (axis.x * s);
	m.elements[2][0] = (axis.z * axis.x * cv) + (axis.y * s);
	m.elements[2][1] = (axis.z * axis.y * cv) - (axis.x * s);
	m.elements[2][2] = (axis.z * axis.z * cv) + c;
	return (m);
}

t_matrix4	rotatel(float a, t_vec3 axis)
{
	return (rotater(-a, axis));
}

t_matrix4	invrotate(t_matrix4 rotation_m)
{
	t_matrix4	m;

	m.elements[0][1] = rotation_m.elements[1][0];
	m.elements[0][2] = rotation_m.elements[2][0];
	m.elements[0][3] = rotation_m.elements[3][0];
	m.elements[1][0] = rotation_m.elements[0][1];
	m.elements[1][2] = rotation_m.elements[2][1];
	m.elements[1][3] = rotation_m.elements[3][1];
	m.elements[2][1] = rotation_m.elements[1][2];
	m.elements[2][0] = rotation_m.elements[0][2];
	m.elements[2][3] = rotation_m.elements[3][2];
	m.elements[3][1] = rotation_m.elements[1][3];
	m.elements[3][2] = rotation_m.elements[2][3];
	m.elements[3][0] = rotation_m.elements[0][3];
	return (m);
}
