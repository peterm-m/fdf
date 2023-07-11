/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:43:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/11 19:32:51 by pedromar         ###   ########.fr       */
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
	int		dx;
	int		dy;
	int		dz;
	int		sx;
	int		sy;
	int		sz;
	int		x0;
	int		y0;
	int		z0;
	int		x1;
	int		y1;
	int		z1;
	int		dm;
	int		i;
	t_vec4	c;
	t_vec4	dc;
}	t_line;

#endif