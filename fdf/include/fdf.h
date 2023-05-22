/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:39:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/22 19:27:55 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define _USE_MATH_DEFINES

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# include "mlxutils.h"
# include "libft.h"
# include "mlx.h"


# include "controls.h"
# include "vector.h"
# include "render.h"

# include "mlxcolor.h"

/*
* Primitive plots
*/
void	ft_put_pixel(t_img img, int x, int y, int color);
void	ft_plot_line(t_img *img, t_pixel r0, t_pixel r1);
void	ft_plot_circle(t_img *img, int color, int rad, t_ivec2 r0);
void	ft_plot_axis(t_img *img, t_cam *cam);
/*
*  plot map
*/
void	to_img(t_img *img, t_cam *cam, t_point p0, t_point p1);
int		ft_plot_map(t_render	*render);

/*
*  contol
*/
void	key_traslation(int key, t_cam *cam);
void	key_rotation(int key, t_cam *cam);
void	key_affin(int key, t_cam *cam);

int		ft_end(t_render *r);
#endif
