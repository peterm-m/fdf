/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector4_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:56:05 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 14:08:49 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec4	ft_minus4(t_vec4 v, t_vec4 traslation)
{
	return ((t_vec4){
		v.x - traslation.x,
		v.y - traslation.y,
		v.z - traslation.z,
		v.w - traslation.w
	});
}

t_vec4	ft_byscalar4(t_vec4 v, float a)
{
	return ((t_vec4){
		v.x * a,
		v.y * a,
		v.z * a,
		v.w * a
	});
}

t_vec4	ft_scaling4(t_vec4 v, t_vec4 factors)
{
	t_vec4	new;

	new.x = v.x * factors.x;
	new.y = v.y * factors.y;
	new.z = v.z * factors.z;
	new.w = v.w * factors.w;
	return (new);
}
