/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:39:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/30 20:21:50 by pedromar         ###   ########.fr       */
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

# include "libft.h"
# include "mlx.h"

# include "vector.h"
# include "trasformations.h"
# include "render.h"
# include "geometric.h"
# include "controls.h"

# include "colors.h"

void	to_image(t_render *r, t_point p0, t_point p1);
int		ft_plot_map(t_render	*render);

#endif
