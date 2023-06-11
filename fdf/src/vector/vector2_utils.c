/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:57:41 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 13:53:36 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	ft_minus2(t_vec2 v, t_vec2 traslation)
{
	return ((t_vec2){
		v.x - traslation.x,
		v.y - traslation.y
	});
}

t_vec2	ft_byscalar2(t_vec2 v, float a)
{
	return ((t_vec2){
		v.x * a,
		v.y * a
	});
}

t_vec2	ft_scaling2(t_vec2 v, t_vec2 factors)
{
	t_vec2	new;

	new.x = v.x * factors.x;
	new.y = v.y * factors.y;
	return (new);
}
