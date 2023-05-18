/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:23:47 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/18 20:44:45 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_cam_rot(t_cam *c)
{
	c->rot[0][0] = cosf(c->c) * cosf(c->a)
		- cosf(c->b) * sinf(c->c) * sinf(c->a);
	c->rot[0][1] = -sinf(c->c) * cosf(c->a)
		- cosf(c->b) * sinf(c->a) * cosf(c->c);
	c->rot[0][2] = sinf(c->b) * sinf(c->a);
	c->rot[1][0] = cosf(c->c) * sinf(c->a)
		+ cosf(c->b) * cosf(c->a) * sinf(c->b);
	c->rot[1][1] = -sinf(c->a) * sinf(c->c)
		+ cosf(c->b) * cosf(c->a) * cosf(c->c);
	c->rot[1][2] = -sinf(c->b) * cosf(c->a);
	c->rot[2][0] = sinf(c->b) * sinf(c->c);
	c->rot[2][1] = sinf(c->b) * cosf(c->c);
	c->rot[2][2] = cosf(c->b);
}

void	set_cam_affin(t_cam *c)
{
	c->affin[0][0] = c->focal;
	c->affin[0][1] = c->focal * c->sh;
	c->affin[0][2] = c->offx;
	c->affin[1][0] = 0;
	c->affin[1][1] = c->focal * c->scale;
	c->affin[1][2] = c->offy;
	c->affin[2][0] = 0;
	c->affin[2][1] = 0;
	c->affin[2][2] = 1;
}

void	set_cam_look(t_cam	*c)
{
	ft_matmul(c->look, c->affin, c->rot);
}

t_cam	*ft_newcam(void )
{
	t_cam	*cam;

	cam = (t_cam *) malloc(sizeof(t_cam));
	cam->t = (t_vec3){0, 0, 10};
	cam->a = 0;
	cam->b = 0;
	cam->c = 0;
	set_cam_rot(cam);
	cam->focal = 10;
	cam->scale = 1;
	cam->sh = 0;
	cam->offx = 0;
	cam->offy = 0;
	set_cam_affin(cam);
	set_cam_look(cam);
	return (cam);
}
