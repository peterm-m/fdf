/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/03 18:10:25 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	print_vec3(t_vec3 v)
{
	printf("x %f y %f z %f \n", v.x, v.y, v.z);
}

void	print_matrix(t_matrix m)
{
	printf("%f %f %f \n", m[0][0], m[0][1], m[0][2]);
	printf("%f %f %f \n", m[1][0], m[1][1], m[1][2]);
	printf("%f %f %f \n", m[2][0], m[2][1], m[2][2]);
}
