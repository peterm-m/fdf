/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:23:47 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/15 20:18:28 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_traslation(t_cam *cam, t_vec3 t)
{
	(cam->pos).x -= t.x;
	(cam->pos).y -= t.y;
	(cam->pos).z -= t.z;
}

void	ft_rotation(t_cam *cam, t_vec3 r)
{
	(cam->base).eu1 += r.x;
	(cam->base).eu2 += r.y;
	(cam->base).eu3 += r.z;
}

void	ft_scalar(t_cam *cam)
{
	
}


t_cam	ft_newcam(void )
{
	t_cam	cam;

	(cam.pos).x = DEFAULT_CAM_XPOS;
	(cam.pos).y = DEFAULT_CAM_YPOS;
	(cam.pos).z = DEFAULT_CAM_ZPOS;
	cam.base.pos.x = DEFAULT_CAM_XPOS;
	cam.base.pos.y = DEFAULT_CAM_YPOS;
	cam.base.pos.z = DEFAULT_CAM_ZPOS;
	(cam.base).e1.x = cosf(DEFAULT_CAM_PHI) * cosf(DEFAULT_CAM_THETA);
	(cam.base).e1.y = cosf(DEFAULT_CAM_PHI) * sinf(DEFAULT_CAM_THETA);
	(cam.base).e1.z = -sinf(DEFAULT_CAM_PHI);
	(cam.base).e2.x = sinf(DEFAULT_CAM_PHI) * sinf(DEFAULT_CAM_THETA);
	(cam.base).e2.y = cosf(DEFAULT_CAM_PHI) * cosf(DEFAULT_CAM_THETA);
	(cam.base).e2.z = 0;
	(cam.base).e3.x = sinf(DEFAULT_CAM_PHI) * cosf(DEFAULT_CAM_THETA);
	(cam.base).e3.y = sinf(DEFAULT_CAM_PHI) * sinf(DEFAULT_CAM_THETA);
	(cam.base).e3.z = cosf(DEFAULT_CAM_PHI);
	cam.focal = 1;
	return (cam);
}

/*
* Initial orientation camera. 
*/