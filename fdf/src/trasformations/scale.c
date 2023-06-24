/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:24:46 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/24 16:45:46 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scale(t_vec3 *s, t_matrix4 *mat)
{
	ft_setrow4(&mat, (t_vec4){s->x, 0, 0, 0}, 0);
	ft_setrow4(&mat, (t_vec4){0, s->y, 0, 0}, 1);
	ft_setrow4(&mat, (t_vec4){0, 0, s->z, 0}, 2);
	ft_setrow4(&mat, (t_vec4){0, 0, 0, 1}, 3);
}