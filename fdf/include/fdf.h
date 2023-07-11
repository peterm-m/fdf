/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:39:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/11 21:34:59 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define _USE_MATH_DEFINES

# include <math.h>
# include <sys/param.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# include "libft.h"
# include "mlx.h"

# include "vector.h"
# include "trasformations.h"
# include "geometric.h"
# include "render.h"
# include "controls.h"

# include "colors.h"

# define DEFAULT_WINX 1024
# define DEFAULT_WINY 1024
# define DEFAULT_IMGSIZX DEFAULT_WINX
# define DEFAULT_IMGSIZY DEFAULT_WINY

void	to_image(t_render *r, t_point p0, t_point p1);
int		ft_plot_map(t_render	*render);

#endif
