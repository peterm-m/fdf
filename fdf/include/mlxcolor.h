/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxcolor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:45:13 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/21 22:30:24 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXCOLOR_H
# define MLXCOLOR_H

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

int		set_rgba(int a, int r, int g, int b);
int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
int		get_alpha(int color);

void	get_gradient(t_color *grad, t_pixel *r0, t_pixel *r1);
int		pixel_color(t_color *grad, t_pixel *r0, t_pixel *r1);

#endif
