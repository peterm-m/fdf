/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traslation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 15:23:09 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/29 20:26:16 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	traslation(t_vec3 *t, t_matrix4 *mat)
{
	ft_setrow4(mat, (t_vec4){1, 0, 0, t->x}, 0);
	ft_setrow4(mat, (t_vec4){0, 1, 0, t->y}, 1);
	ft_setrow4(mat, (t_vec4){0, 0, 1, t->z}, 2);
	ft_setrow4(mat, (t_vec4){0, 0, 0, 1}, 3);
}
