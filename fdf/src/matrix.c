/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:39:23 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/07 20:31:06 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	ft_getcol(t_matrix *mat, int col)
{
	return ((t_vec3){
		(*mat)[0][col],
	(*mat)[1][col],
	(*mat)[2][col]});
}

t_vec3	ft_getrow(t_matrix *mat, int row)
{
	return ((t_vec3){
		(*mat)[row][0],
	(*mat)[row][1],
	(*mat)[row][2]});
}

void	ft_setcol(t_matrix *mat, t_vec3 data, int col)
{
	(*mat)[0][col] = data.x;
	(*mat)[1][col] = data.y;
	(*mat)[2][col] = data.z;
}

void	ft_setrow(t_matrix *mat, t_vec3 data, int row)
{
	(*mat)[row][0] = data.x;
	(*mat)[row][1] = data.y;
	(*mat)[row][2] = data.z;
}
