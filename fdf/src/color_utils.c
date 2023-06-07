/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:17:26 by pedro             #+#    #+#             */
/*   Updated: 2023/06/07 18:23:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_gradient(t_color *grad, t_pixel *r0, t_pixel *r1)
{
	float	len;

	len = sqrt(abs(r0->r.x - r1->r.x) * abs(r0->r.x - r1->r.x)
			+ abs(r0->r.y - r1->r.y) * abs(r0->r.y - r1->r.y));
	grad->alpha = (float)((get_alpha(r1->color)) - (get_alpha(r0->color)))
		/ len;
	grad->red = (float)((get_red(r1->color)) - (get_red(r0->color)))
		/ len;
	grad->green = (float)((get_green(r1->color)) - (get_green(r0->color)))
		/ len;
	grad->blue = (float)((get_blue(r1->color)) - (get_blue(r0->color)))
		/ len;
}

int	pixel_color(t_color *grad, t_pixel *r0, t_pixel *r1)
{
	float	len;

	len = sqrt(abs(r0->r.x - r1->r.x) * abs(r0->r.x - r1->r.x)
			+ abs(r0->r.y - r1->r.y) * abs(r0->r.y - r1->r.y));
	return (set_rgba((get_alpha(r0->color)) + round(len * grad->alpha),
			(get_red(r0->color)) + round(len * grad->red),
			(get_green(r0->color)) + round(len * grad->green),
			(get_blue(r0->color)) + round(len * grad->blue)));
}
