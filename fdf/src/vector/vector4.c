/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/29 20:03:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_dot_product4(t_vec4 a, t_vec4 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}

t_vec4	ft_normalize4(t_vec4 a)
{
	float	norm;

	norm = sqrtf(ft_dot_product4(a, a));
	if (norm == 0)
		return ((t_vec4){0, 0, 0, 0});
	return ((t_vec4){
		a.x / norm,
		a.y / norm,
		a.z / norm,
		a.w / norm
	});
}

t_vec4	ft_bymat4(t_vec4 *a, t_matrix4 mat)
{
	return ((t_vec4){
		a->x * mat[0][0] + a->y * mat[0][1] + a->z * mat[0][2]
		+ a->w * mat[0][3],
		a->x * mat[1][0] + a->y * mat[1][1] + a->z * mat[1][2]
		+ a->w * mat[1][3],
		a->x * mat[2][0] + a->y * mat[2][1] + a->z * mat[2][2]
		+ a->w * mat[2][3],
		a->x * mat[3][0] + a->y * mat[3][1] + a->z * mat[3][2]
		+ a->w * mat[3][3],
		});
}
