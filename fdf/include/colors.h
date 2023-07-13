/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:45:13 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/13 21:15:11 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/*
* ARGB-color space utils
*/
typedef struct s_color {
	float	alpha;
	float	red;
	float	green;
	float	blue;
}	t_color;

# define CL_RED 8
# define CL_GREEN 4
# define CL_BLUE 2
# define CL_ALPHA 1

# define CL_MASK_ALPHA 0xFF000000
# define CL_MASK_RED   0x00FF0000
# define CL_MASK_GREEN 0x0000FF00
# define CL_MASK_BLUE  0x000000FF

# define CL_POS_ALPHA 24
# define CL_POS_RED 16
# define CL_POS_GREEN 8
# define CL_POS_BLUE 0

int		set_rgba(t_vec4 color);
int		get_r(float color);
int		get_g(float color);
int		get_b(float color);
int		get_a(float color);

#endif
