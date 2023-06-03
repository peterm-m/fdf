/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:03:56 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/03 19:19:02 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cam2	*ft_newcam2(void )
{
	t_cam2	*cam;

	cam = (t_cam2 *) malloc(sizeof(t_cam2));
	cam->cam_pos = (t_vec3){0, 0, 10};
	cam->azimuth = 0;
	cam->polar = 0;
}
// posibles problemas si cam_pos == 0