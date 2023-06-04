/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:55:57 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/04 18:29:34 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_dot_product(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	ft_vector_product(t_vec3 *a, t_vec3 *b)
{
	return ((t_vec3){
		a->y * b->z - a->z * b->y,
		a->z * b->x - a->x * b->z,
		a->x * b->y - a->y * b->x
	});
}

t_vec3	ft_normalize(t_vec3 a)
{
	float	norm;

	norm = sqrt(ft_dot_product(a, a));
	if (norm != 0)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3){
		a.x / norm,
		a.y / norm,
		a.z / norm
	});
}

t_vec3	ft_bymat(t_vec3 *a, t_matrix mat)
{
	return ((t_vec3){
		a->x * mat[0][0] + a->y * mat[0][1] + a->z * mat[0][2],
		a->x * mat[1][0] + a->y * mat[1][1] + a->z * mat[1][2],
		a->x * mat[2][0] + a->y * mat[2][1] + a->z * mat[2][2]
		});
}

void	ft_matmul(t_matrix res, t_matrix a, t_matrix b)
{
	res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
	res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
	res[0][2] = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2];
	res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
	res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];
	res[1][2] = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2];
	res[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0];
	res[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1];
	res[2][2] = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2];
}
