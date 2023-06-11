/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 18:39:23 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 13:42:44 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec3	ft_getcol3(t_matrix3 *mat, int col)
{
	return ((t_vec3){
		(*mat)[0][col],
	(*mat)[1][col],
	(*mat)[2][col]});
}

t_vec3	ft_getrow3(t_matrix3 *mat, int row)
{
	return ((t_vec3){
		(*mat)[row][0],
	(*mat)[row][1],
	(*mat)[row][2]});
}

void	ft_setcol3(t_matrix3 *mat, t_vec3 data, int col)
{
	(*mat)[0][col] = data.x;
	(*mat)[1][col] = data.y;
	(*mat)[2][col] = data.z;
}

void	ft_setrow3(t_matrix3 *mat, t_vec3 data, int row)
{
	(*mat)[row][0] = data.x;
	(*mat)[row][1] = data.y;
	(*mat)[row][2] = data.z;
}

void	ft_matmul3(t_matrix3 res, t_matrix3 a, t_matrix3 b)
{
	res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0] + a[0][2] * b[2][0];
	res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1] + a[0][2] * b[2][1];
	res[0][2] = a[0][0] * b[0][2] + a[0][1] * b[1][2] + a[0][2] * b[2][2];
	res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0] + a[1][2] * b[2][0];
	res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1] + a[1][2] * b[2][1];
	res[1][2] = a[1][0] * b[0][2] + a[1][1] * b[1][2] + a[1][2] * b[2][2];
	res[2][0] = a[2][0] * b[0][0] + a[2][1] * b[1][0] + a[2][2] * b[2][0];
	res[2][1] = a[2][0] * b[0][1] + a[2][1] * b[1][1] + a[2][2] * b[2][1];
	res[2][2] = a[2][0] * b[0][2] + a[2][1] * b[1][2] + a[2][2] * b[2][2];
}
