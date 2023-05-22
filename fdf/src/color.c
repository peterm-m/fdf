/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:51:46 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/21 18:32:01 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_rgba(int a, int r, int g, int b)
{
	return ((r << CL_POS_RED) + (g << CL_POS_GREEN)
		+ (b << CL_POS_BLUE) + (a << CL_POS_ALPHA));
}

int	get_red(int color)
{
	return ((color & CL_MASK_RED) >> CL_POS_RED);
}

int	get_green(int color)
{
	return ((color & CL_MASK_GREEN) >> CL_POS_GREEN);
}

int	get_blue(int color)
{
	return ((color & CL_MASK_BLUE) >> CL_POS_BLUE);
}

int	get_alpha(int color)
{
	return ((color & CL_MASK_ALPHA) >> CL_POS_ALPHA);
}

/*
**  color is 0xAARRGGBB format
*/