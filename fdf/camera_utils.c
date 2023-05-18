/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:23:47 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/18 20:44:58 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotation(t_cam *cam, t_vec3 r)
{
	cam->a += r.x;
	cam->b += r.y;
	cam->c += r.z;
}

/*
* Initial orientation camera. 
*/