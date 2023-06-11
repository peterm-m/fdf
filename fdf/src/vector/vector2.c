/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:48:05 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 13:50:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_dot_product2(t_vec2 a, t_vec2 b)
{
	return (a.x * b.x + a.y * b.y);
}

t_vec2	ft_normalize2(t_vec2 a)
{
	float	norm;

	norm = sqrt(ft_dot_product2(a, a));
	if (norm == 0)
		return ((t_vec2){0, 0});
	return ((t_vec2){
		a.x / norm,
		a.y / norm
	});
}

t_vec2	ft_bymat2(t_vec2 *a, t_matrix2 mat)
{
	return ((t_vec2){
		a->x * mat[0][0] + a->y * mat[0][1],
		a->x * mat[1][0] + a->y * mat[1][1]
		});
}
