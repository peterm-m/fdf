/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:45:08 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 13:54:57 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec2	ft_getcol2(t_matrix2 *mat, int col)
{
	return ((t_vec2){
		(*mat)[0][col],
	(*mat)[1][col]});
}

t_vec2	ft_getrow2(t_matrix2 *mat, int row)
{
	return ((t_vec2){
		(*mat)[row][0],
	(*mat)[row][1]});
}

void	ft_setcol2(t_matrix2 *mat, t_vec2 data, int col)
{
	(*mat)[0][col] = data.x;
	(*mat)[1][col] = data.y;
}

void	ft_setrow2(t_matrix2 *mat, t_vec2 data, int row)
{
	(*mat)[row][0] = data.x;
	(*mat)[row][1] = data.y;
}

void	ft_matmul2(t_matrix2 res, t_matrix2 a, t_matrix2 b)
{
	res[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0];
	res[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1];
	res[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0];
	res[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1];
}
