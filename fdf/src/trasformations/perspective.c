/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:36:59 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/07 21:27:27 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4	perspectiver(float fov, float aspect, float near, float far)
{
	t_matrix4	m;
	float		cot;

	m = ft_ident4();
	cot = 1.0f / tanf(fov / 2.0f);
	m.elements[0][0] = cot / aspect;
	m.elements[1][1] = cot;
	m.elements[2][3] = -1.0f;
	m.elements[2][2] = (near + far) / (near - far);
	m.elements[3][2] = (2.0f * near * far) / (near - far);
	return (m);
}

t_matrix4	invperspectiver(t_matrix4 pers_m)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[0][0] = 1.0f / pers_m.elements[0][0];
	m.elements[1][1] = 1.0f / pers_m.elements[1][1];
	m.elements[2][2] = 0.0f;
	m.elements[2][3] = 1.0f / pers_m.elements[3][2];
	m.elements[3][3] = pers_m.elements[2][2] * m.elements[2][3];
	m.elements[3][2] = pers_m.elements[2][3];
	return (m);
}

t_matrix4	perspectivel(float fov, float aspect, float near, float far)
{
	t_matrix4	m;

	m = ft_ident4();
	m = perspectiver(fov, aspect, near, far);
	m.elements[2][2] = -m.elements[2][2];
	m.elements[2][3] = -m.elements[2][3];
	return (m);
}

t_matrix4	invperspectivel(t_matrix4 pers_m)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[0][0] = 1.0f / pers_m.elements[0][0];
	m.elements[1][1] = 1.0f / pers_m.elements[1][1];
	m.elements[2][2] = 0.0f;
	m.elements[2][3] = 1.0f / pers_m.elements[3][2];
	m.elements[3][3] = pers_m.elements[2][2] * -m.elements[2][3];
	m.elements[3][2] = pers_m.elements[2][3];
	return (m);
}
