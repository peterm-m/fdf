/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divv2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:56:42 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/06 20:57:13 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	ft_divv2f(t_vec2 v, float f)
{
	t_vec2	v1;

	v1.x = v.x / f;
	v1.y = v.y / f;
	return (v1);
}

t_vec3	ft_divv3f(t_vec3 v, float f)
{
	t_vec3	v1;

	v1.x = v.x / f;
	v1.y = v.y / f;
	v1.z = v.z / f;
	return (v1);
}

t_vec4	ft_divv4f(t_vec4 v, float f)
{
	t_vec4	v1;

	v1.x = v.x / f;
	v1.y = v.y / f;
	v1.z = v.z / f;
	v1.w = v.w / f;
	return (v1);
}
