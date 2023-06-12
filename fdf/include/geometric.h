/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:43:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/12 20:03:30 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRIC_H
# define GEOMETRIC_H

# include "fdf.h"

typedef struct s_point {
	t_vec3	r;
	int		color;
}	t_point;

typedef struct s_line {
	t_pixel	p0;
	t_pixel	p1;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		dcolor;
}	t_line;

typedef struct s_circle {
	t_point	p0;
	float	rad;
	int		color;
}	t_circle;

typedef struct s_pixel {
	int	x;
	int	y;
	int	color;
}	t_pixel;

t_point		to_ndc(t_render *r, int x, int y);

/*
*	Primitive plots
*/
void		ft_put_pixel(t_img *img, t_pixel *p);
void		ft_plot_line(t_img *img, t_line *l);
//void		ft_plot_circle(t_img *img, t_circle *c);
//void		ft_plot_axis(t_img *img, t_cam *cam);

#endif