/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:18:44 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/15 20:10:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_manager(int key, t_render *r)
{
	ft_bzero((void *)(r->img->addr), r->img->h * r->img->size_line
		+ r->img->w * (r->img->bpp / 8));
	printf("%d\n", key);
	if (key == F_ESC)
		ft_end_program(r);
	else if (key == Q_ZPLUS || key == E_ZMIN || key == W_XPLUS || key == S_XMIN
		|| key == A_YPLUS || key == D_YMIN)
		key_traslation(key, r->cam);
	else if (key == U_APLUS || key == O_AMIN || key == I_BPLUS
		|| key == K_BMIN || key == J_CPLUS || key == L_CMIN
		|| key == ANG_RESTORE)
		key_rotation(key, r->cam);
	else if (key == F_FOCPLUS || key == G_FOCMIN || key == B_SCALEPLUS
		|| key == N_SCALEMIN || key == R_SHPLUS || key == T_SHMIN
		|| key == Z_OFFXPLUS || key == X_OFFXMIN || key == C_OFFYPLUS
		|| key == V_OFFYMIN)
		key_affin(key, r->cam);
	return (EXIT_SUCCESS);
}

int	mouse_manager(int buttom, int x, int y, t_render *r)
{
	ft_bzero((void *)(r->img->addr), r->img->h * r->img->size_line
		+ r->img->w * (r->img->bpp / 8));
	ft_printf("bu %d, x %d, y %d \n", buttom, x, y);
	return (0);
}

void	key_traslation(int key, t_render *r)
{
	ft_bzero((void *)(r->img->addr), r->img->h * r->img->size_line
		+ r->img->w * (r->img->bpp / 8));
	if (key == 0) /*#CONTINUE#*/
		return ;
	//else if (key == E_ZMIN)
	//	(cam->t).z -= STEP_Z;
	//else if (key == W_XPLUS)
	//	(cam->t).y += STEP_X;
	//else if (key == S_XMIN)
	//	(cam->t).y -= STEP_X;
	//else if (key == A_YPLUS)
	//	(cam->t).x += STEP_Y;
	//else if (key == D_YMIN)
	//	(cam->t).x -= STEP_Y;
	//set_cam_look(cam);
	//print_cam(*cam);
	return ;
}

void	key_rotation(int key, t_render *r)
{
//	if (key == U_APLUS) /*#CONTINUE#*/
//		cam->a += STEP_A;
//	else if (key == O_AMIN)
//		cam->a -= STEP_A;
//	else if (key == I_BPLUS)
//		cam->b += STEP_B;
//	else if (key == K_BMIN)
//		cam->b -= STEP_B;
//	else if (key == J_CPLUS)
//		cam->c += STEP_C;
//	else if (key == L_CMIN)
//		cam->c -= STEP_C;
//	else if (key == ANG_RESTORE)
//	{
//		cam->a = 0;
//		cam->b = 0;
//		cam->c = 0;
//	}
//	set_cam_rot(cam);
//	set_cam_look(cam);
//	print_cam(*cam);
	return ;
}

void	key_affin(int key, t_render *r)
{
	//if (key == F_FOCPLUS) /*#CONTINUE#*/
	//	cam->focal += STEP_FOC;
	//else if (key == G_FOCMIN && cam->focal > MIN_FOC)
	//	cam->focal -= STEP_FOC;
	//else if (key == B_SCALEPLUS)
	//	cam->scale += STEP_SCALE;
	//else if (key == N_SCALEMIN && cam->scale > MIN_SCALE)
	//	cam->scale -= STEP_SCALE;
	//else if (key == R_SHPLUS)
	//	cam->sh += STEP_SH;
	//else if (key == T_SHMIN)
	//	cam->sh -= STEP_SH;
	//else if (key == Z_OFFXPLUS)
	//	cam->offx += STEP_OFFX;
	//else if (key == X_OFFXMIN)
	//	cam->offx -= STEP_OFFX;
	//else if (key == C_OFFYPLUS)
	//	cam->offy += STEP_OFFY;
	//else if (key == V_OFFYMIN)
	//	cam->offy -= STEP_OFFY;
	//set_cam_affin(cam);
	//set_cam_look(cam);
	//print_cam(*cam);
	return ;
}
