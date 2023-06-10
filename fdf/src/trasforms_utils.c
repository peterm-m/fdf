/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasforms_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 18:56:05 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/10 19:03:40 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec4	ft_bytrast(t_vec4 *a, t_trasform mat)
{
	return ((t_vec4){
		a->x * mat[0][0] + a->y * mat[0][1] + a->z * mat[0][2]
		+ a->w * mat[0][3],
		a->x * mat[1][0] + a->y * mat[1][1] + a->z * mat[1][2]
		+ a->w * mat[1][3],
		a->x * mat[2][0] + a->y * mat[2][1] + a->z * mat[2][2]
		+ a->w * mat[2][3],
		a->x * mat[3][0] + a->y * mat[3][1] + a->z * mat[3][2]
		+ a->w * mat[3][3],
		});
}
