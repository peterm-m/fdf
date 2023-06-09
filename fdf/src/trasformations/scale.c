/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 18:37:13 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/10 02:48:32 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_matrix4	scale(t_vec3 scale)
{
	t_matrix4	m;

	m = ft_ident4();
	m.elements[0][0] = scale.x;
	m.elements[1][1] = scale.y;
	m.elements[2][2] = scale.z;
	return (m);
}

t_matrix4	invscale(t_matrix4 scale_m)
{
	t_matrix4	m;

	m = scale_m;
	m.elements[0][0] = 1.0f / m.elements[0][0];
	m.elements[1][1] = 1.0f / m.elements[1][1];
	m.elements[2][2] = 1.0f / m.elements[2][2];
	return (m);
}
