/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/15 18:51:27 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	ft_sum(t_vec3 v, t_vec3 traslation)
{
	t_vec3	sum;

	sum.x = v.x + traslation.x;
	sum.y = v.y + traslation.y;
	sum.z = v.z + traslation.z;
	return (sum);
}

t_vec3	ft_byscalar(t_vec3 v, float a)
{
	t_vec3	new;

	new.x = v.x * a;
	new.y = v.y * a;
	new.z = v.z * a;
	return (new);
}

t_vec3	ft_scaling(t_vec3 v, t_vec3 factors)
{
	t_vec3	new;

	new.x = v.x * factors.x;
	new.y = v.y * factors.y;
	new.z = v.z * factors.z;
	return (new);
}

//void	ft_rotation3(t_vec3 *v, t_vec3 *rotation)
//{
//	v = (void *) v;
//	rotation = (void *) rotation;
//}
