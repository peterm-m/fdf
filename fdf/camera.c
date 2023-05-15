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

t_cam	ft_newcam(void )
{
	t_cam	cam;

	(cam.pos).x = DEFAULT_CAM_XPOS;
	(cam.pos).y = DEFAULT_CAM_YPOS;
	(cam.pos).z = DEFAULT_CAM_ZPOS;
	(cam.base).e1.x = -sinf(DEFAULT_CAM_PHI) * cosf(DEFAULT_CAM_THETA);
	(cam.base).e1.y = -sinf(DEFAULT_CAM_PHI) * sinf(DEFAULT_CAM_THETA);
	(cam.base).e1.z = -cosf(DEFAULT_CAM_PHI);
	(cam.base).e2.x = -sinf(DEFAULT_CAM_PHI) * sinf(DEFAULT_CAM_THETA);
	(cam.base).e2.y = -cosf(DEFAULT_CAM_PHI) * cosf(DEFAULT_CAM_THETA);
	(cam.base).e2.z = 0;
	(cam.base).e3.x = cosf(DEFAULT_CAM_PHI) * cosf(DEFAULT_CAM_THETA);
	(cam.base).e3.y = cosf(DEFAULT_CAM_PHI) * sinf(DEFAULT_CAM_THETA);
	(cam.base).e3.z = -sinf(DEFAULT_CAM_PHI);
	return (cam);
}
