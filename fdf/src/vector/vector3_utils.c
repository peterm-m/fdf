/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 13:47:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	ft_minus3(t_vec3 v, t_vec3 traslation)
{
	return ((t_vec3){
		v.x - traslation.x,
		v.y - traslation.y,
		v.z - traslation.z
	});
}

t_vec3	ft_byscalar3(t_vec3 v, float a)
{
	return ((t_vec3){
		v.x * a,
		v.y * a,
		v.z * a
	});
}

t_vec3	ft_scaling3(t_vec3 v, t_vec3 factors)
{
	t_vec3	new;

	new.x = v.x * factors.x;
	new.y = v.y * factors.y;
	new.z = v.z * factors.z;
	return (new);
}
