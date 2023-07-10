/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:43:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/10 21:41:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRIC_H
# define GEOMETRIC_H

# include "fdf.h"

typedef struct s_circle {
	t_vec4	p0;
	float	rad;
	int		color;
}	t_circle;

typedef struct s_line {
	int		x0;
	int		y0;
	int		z0;
	t_vec4	c0;
	int		x1;
	int		y1;
	int		z1;
	t_vec4	c1;
}	t_line;


/*
*	Primitive plots
*/

//void		ft_plot_circle(t_img *img, t_circle *c);
//void		ft_plot_axis(t_img *img, t_cam *cam);

#endif