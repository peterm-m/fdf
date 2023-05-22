/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:23:47 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/22 17:29:18 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_cam_rot(t_cam *c)
{
	c->rot[0][0] = cosf(c->c) * cosf(c->b);
	c->rot[1][0] = -cosf(c->b) * sinf(c->c);
	c->rot[2][0] = -sinf(c->b);
	c->rot[0][1] = sinf(c->a) * sinf(c->b) * cosf(c->c)
		+ cosf(c->a) * sinf(c->c);
	c->rot[1][1] = -sinf(c->a) * sinf(c->b) * sinf(c->c)
		+ cosf(c->a) * cosf(c->c);
	c->rot[2][1] = -sinf(c->a) * cosf(c->b);
	c->rot[0][2] = cosf(c->a) * sinf(c->b) * cosf(c->c)
		+ sinf(c->a) * sinf(c->c);
	c->rot[1][2] = cosf(c->a) * sinf(c->b) * sinf(c->c)
		+ sinf(c->a) * cosf(c->c);
	c->rot[2][2] = cosf(c->a) * cosf(c->b);
}

void	set_cam_affin(t_cam *c)
{
	c->affin[0][0] = c->focal;
	c->affin[0][1] = c->focal * c->sh;
	c->affin[0][2] = 0;
	c->affin[1][0] = 0;
	c->affin[1][1] = c->focal * c->scale;
	c->affin[1][2] = 0;
	c->affin[2][0] = 0;
	c->affin[2][1] = 0;
	c->affin[2][2] = 0.1;
}

void	set_cam_look(t_cam	*cam)
{
	cam->cam_pos = ((t_vec3){
			(cam->t).x * cam->rot[0][0] + (cam->t).y * cam->rot[1][0]
			+ (cam->t).z * cam->rot[2][0],
			(cam->t).x * cam->rot[0][1] + (cam->t).y * cam->rot[1][1]
			+ (cam->t).z * cam->rot[2][1],
			(cam->t).x * cam->rot[0][2] + (cam->t).y * cam->rot[1][2]
			+ (cam->t).z * cam->rot[2][2]
		});
	ft_matmul(cam->look, cam->affin, cam->rot);
}

t_cam	*ft_newcam(void )
{
	t_cam	*cam;

	cam = (t_cam *) malloc(sizeof(t_cam));
	cam->t = (t_vec3){0, 0, -10};
	cam->a = M_PI_2 / 3;
	cam->b = 0;
	cam->c = M_PI_4;
	cam->focal = 10;
	cam->scale = 1;
	cam->sh = 0;
	cam->offx = 0;
	cam->offy = 0;
	set_cam_rot(cam);
	set_cam_affin(cam);
	set_cam_look(cam);
	return (cam);
}

void	print_cam( t_cam cam)
{
	printf("TRASLATION\n");
	print_vec3(cam.t);
	printf("ANGLES\na %f b %f c %f\n",
		cam.a, cam.b, cam.c);
	printf("FOCAL %f\n", cam.focal);
	printf("SCALE %f\n", cam.scale);
	printf("SH %f\n", cam.sh);
	printf("OFFX %f\n", cam.offx);
	printf("OFFY %f\n", cam.offy);
	printf("TROTATION MATRIX\n");
	print_matrix(cam.rot);
	printf("AFFIN MATRIX\n");
	print_matrix(cam.affin);
	printf("LOOK MATRIX\n");
	print_matrix(cam.look);
}
