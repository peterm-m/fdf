/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:18:44 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/02 18:38:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_traslation(int key, t_cam *cam)
{
	if (key == Q_ZPLUS)
		(cam->t).z += STEP_Z;
	else if (key == E_ZMIN)
		(cam->t).z -= STEP_Z;
	else if (key == W_XPLUS)
		(cam->t).y += STEP_X;
	else if (key == S_XMIN)
		(cam->t).y -= STEP_X;
	else if (key == A_YPLUS)
		(cam->t).x += STEP_Y;
	else if (key == D_YMIN)
		(cam->t).x -= STEP_Y;
	set_cam_look(cam);
	print_cam(*cam);
}

void	key_rotation(int key, t_cam *cam)
{
	if (key == U_APLUS)
		cam->a += STEP_A;
	else if (key == O_AMIN)
		cam->a -= STEP_A;
	else if (key == I_BPLUS)
		cam->b += STEP_B;
	else if (key == K_BMIN)
		cam->b -= STEP_B;
	else if (key == J_CPLUS)
		cam->c += STEP_C;
	else if (key == L_CMIN)
		cam->c -= STEP_C;
	else if (key == ANG_RESTORE)
	{
		cam->a = 0;
		cam->b = 0;
		cam->c = 0;
	}
	set_cam_rot(cam);
	set_cam_look(cam);
	print_cam(*cam);
}

void	key_affin(int key, t_cam *cam)
{
	if (key == F_FOCPLUS)
		cam->focal += STEP_FOC;
	else if (key == G_FOCMIN && cam->focal > MIN_FOC)
		cam->focal -= STEP_FOC;
	else if (key == B_SCALEPLUS)
		cam->scale += STEP_SCALE;
	else if (key == N_SCALEMIN && cam->scale > MIN_SCALE)
		cam->scale -= STEP_SCALE;
	else if (key == R_SHPLUS)
		cam->sh += STEP_SH;
	else if (key == T_SHMIN)
		cam->sh -= STEP_SH;
	else if (key == Z_OFFXPLUS)
		cam->offx += STEP_OFFX;
	else if (key == X_OFFXMIN)
		cam->offx -= STEP_OFFX;
	else if (key == C_OFFYPLUS)
		cam->offy += STEP_OFFY;
	else if (key == V_OFFYMIN)
		cam->offy -= STEP_OFFY;
	set_cam_affin(cam);
	set_cam_look(cam);
	print_cam(*cam);
}
