/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:55:57 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 13:17:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_dot_product3(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	ft_vector_product3(t_vec3 *a, t_vec3 *b)
{
	return ((t_vec3){
		a->y * b->z - a->z * b->y,
		a->z * b->x - a->x * b->z,
		a->x * b->y - a->y * b->x
	});
}

t_vec3	ft_normalize3(t_vec3 a)
{
	float	norm;

	norm = sqrt(ft_dot_product3(a, a));
	if (norm == 0)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3){
		a.x / norm,
		a.y / norm,
		a.z / norm
	});
}

t_vec3	ft_bymat3(t_vec3 *a, t_matrix3 mat)
{
	return ((t_vec3){
		a->x * mat[0][0] + a->y * mat[0][1] + a->z * mat[0][2],
		a->x * mat[1][0] + a->y * mat[1][1] + a->z * mat[1][2],
		a->x * mat[2][0] + a->y * mat[2][1] + a->z * mat[2][2]
		});
}
