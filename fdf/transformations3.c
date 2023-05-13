/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/13 16:07:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tr_traslation3(t_vec3 *v, t_vec3 traslation)
{
	v->x += traslation.x;
	v->y += traslation.x;
	v->z += traslation.z;
}

void	tr_scaling3(t_vec3 *v, t_vec3 *scaling_factor)
{
	v = (void *) v;
	scaling_factor = (void *) scaling_factor;
}

void	tr_rotation3(t_vec3 *v, t_vec3 *rotation)
{
	v = (void *) v;
	rotation = (void *) rotation;
}
