/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:18:44 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/18 21:01:57 by pedromar         ###   ########.fr       */
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
		(cam->t).x += STEP_X;
	else if (key == S_XMIN)
		(cam->t).x -= STEP_X;
	else if (key == A_YPLUS)
		(cam->t).y += STEP_Y;
	else if (key == D_YMIN)
		(cam->t).y -= STEP_Y;
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
	set_cam_rot(cam);
	set_cam_look(cam);
}

void	key_affin(int key, t_cam *cam)
{
	if (key == F_FOCPLUS)
		return ;
	else if (key == G_FOCMIN)
		return ;
	else if (key == B_SCALEPLUS)
		return ;
	else if (key == N_SCALEMIN)
		return ;
	else if (key == R_SHPLUS)
		return ;
	else if (key == T_SHMIN)
		return ;
	else if (key == Z_OFFXPLUS)
		return ;
	else if (key == X_OFFXMIN)
		return ;
	else if (key == C_OFFYPLUS)
		return ;
	else if (key == V_OFFYMIN)
		return ;
	cam = (void *) cam;
}
