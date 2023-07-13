/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:51:46 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/13 21:45:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  color is 0xAARRGGBB format
*/

#include "fdf.h"

int	set_rgba(t_vec4	c)
{
	return (((char)c.a << CL_POS_ALPHA) + ((char)c.r << CL_POS_RED)
		+ ((char)c.g << CL_POS_GREEN) + ((char)c.b << CL_POS_BLUE));
}

int	get_r(float color)
{
	return (((int)color & CL_MASK_RED) >> CL_POS_RED);
}

int	get_g(float color)
{
	return (((int)color & CL_MASK_GREEN) >> CL_POS_GREEN);
}

int	get_b(float color)
{
	return (((int)color & CL_MASK_BLUE) >> CL_POS_BLUE);
}

int	get_a(float color)
{
	return (((int)color & CL_MASK_ALPHA) >> CL_POS_ALPHA);
}
