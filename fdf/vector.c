/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:55:57 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/15 20:18:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_dot_product(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	ft_vector_product(t_vec3 *a, t_vec3 *b)
{
	t_vec3	axb;

	axb.x = a->y * b->z - a->z * b->y;
	axb.y = a->z * b->x - a->x * b->z;
	axb.z = a->x * b->y - a->y * b->x;
	return (axb);
}

t_vec3	ft_normalize(t_vec3 a)
{
	t_vec3	norm_a;
	float	norm;

	norm = sqrt(ft_dot_product(a, a));
	norm_a.x = a.x / norm;
	norm_a.y = a.y / norm;
	norm_a.z = a.z / norm;
	return (norm_a);
}

t_vec3	ft_matmul(t_vec3 *a, float **mat)
{
	t_vec3	b;

	b.x = a->x * mat[0][0] + a->y * mat[0][1] + a->z * mat[0][2];
	b.y = a->x * mat[1][0] + a->y * mat[1][1] + a->z * mat[1][2];
	b.z = a->x * mat[2][0] + a->y * mat[2][1] + a->z * mat[2][2];
	return (b);
}
