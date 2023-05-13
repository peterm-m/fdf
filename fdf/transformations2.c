/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:08:03 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/13 16:08:46 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	tr_traslation2(t_vec2 *v, t_vec2 traslation)
{
	v->x += traslation.x;
	v->y += traslation.x;
}

void	tr_scaling2(t_vec2 *v, t_vec2 *scaling_factor)
{
	v = (void *) v;
	scaling_factor = (void *) scaling_factor;
}

void	tr_rotation2(t_vec2 *v, t_vec2 *rotation)
{
	v = (void *) v;
	rotation = (void *) rotation;
}
