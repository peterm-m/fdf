/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/10 19:51:21 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


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

t_vec3	ft_traslation(t_vec3 v, t_vec3 traslation)
{
	return ((t_vec3){
		v.x - traslation.x,
		v.y - traslation.y,
		v.z - traslation.z
	});
}

t_vec3	ft_byscalar(t_vec3 v, float a)
{
	return ((t_vec3){
		v.x * a,
		v.y * a,
		v.z * a
	});
}

t_vec3	ft_scaling(t_vec3 v, t_vec3 factors)
{
	t_vec3	new;

	new.x = v.x * factors.x;
	new.y = v.y * factors.y;
	new.z = v.z * factors.z;
	return (new);
}

//void	print_vec3(t_vec3 m)
//{
//	printf("%f %f %f \n", m.x, m.y, m.z);
//}

//void	print_matrix(t_matrix m)
//{
//	printf("%f %f %f \n", m[0][0], m[0][1], m[0][2]);
//	printf("%f %f %f \n", m[1][0], m[1][1], m[1][2]);
//	printf("%f %f %f \n", m[2][0], m[2][1], m[2][2]);
//}
//
//void	print_tras(t_trasform m)
//{
//	printf("%f %f %f %f\n", m[0][0], m[0][1], m[0][2], m[0][3]);
//	printf("%f %f %f %f\n", m[1][0], m[1][1], m[1][2], m[1][3]);
//	printf("%f %f %f %f\n", m[2][0], m[2][1], m[2][2], m[2][3]);
//	printf("%f %f %f %f\n", m[3][0], m[3][1], m[3][2], m[3][3]);
//}
//