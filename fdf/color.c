/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 11:51:46 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/15 15:17:37 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_color_rgba(int a, int r, int g, int b)
{
	return ((r << CL_POS_RED) + (g << CL_POS_GREEN)
		+ (b << CL_POS_BLUE) + (a << CL_POS_ALPHA));
}

int	ft_r_color(int color)
{
	return ((color & CL_MASK_RED) >> CL_POS_RED);
}

int	ft_g_color(int color)
{
	return ((color & CL_MASK_GREEN) >> CL_POS_GREEN);
}

int	ft_b_color(int color)
{
	return ((color & CL_MASK_BLUE) >> CL_POS_BLUE);
}

int	ft_a_color(int color)
{
	return ((color & CL_MASK_ALPHA) >> CL_POS_ALPHA);
}

/*
**  color is 0xAARRGGBB format
*/