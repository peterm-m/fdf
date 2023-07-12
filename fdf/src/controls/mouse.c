/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:26:58 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/12 21:28:51 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_motion_manager(int x, int y, t_render *render)
{
	render = (void *) render;
	printf("move x %d y %d \n", x, y);
	return (0);
}

int	mouse_button_manager(int buttom, int x, int y, t_render *render)
{
	render = (void *) render;
	printf("press %d x %d y %d \n", buttom, x, y);
	return (buttom);
}
