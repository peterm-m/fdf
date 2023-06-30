/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:20 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/30 21:12:08 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec4	ft_getcol4(t_matrix4 *mat, int col)
{
	return ((t_vec4){
		(*mat)[0][col],
	(*mat)[1][col],
	(*mat)[2][col],
	(*mat)[3][col]});
}

t_vec4	ft_getrow4(t_matrix4 *mat, int row)
{
	return ((t_vec4){
		(*mat)[row][0],
	(*mat)[row][1],
	(*mat)[row][2],
	(*mat)[row][3]});
}

void	ft_setcol4(t_matrix4 *mat, t_vec4 data, int col)
{
	(*mat)[0][col] = data.x;
	(*mat)[1][col] = data.y;
	(*mat)[2][col] = data.z;
	(*mat)[3][col] = data.w;
}

void	ft_setrow4(t_matrix4 *mat, t_vec4 data, int row)
{
	(*mat)[row][0] = data.x;
	(*mat)[row][1] = data.y;
	(*mat)[row][2] = data.z;
	(*mat)[row][3] = data.w;
}

void	ft_matmul4(t_matrix4 *res, t_matrix4 a, t_matrix4 b)
{
	t_matrix4	*aa;
	t_matrix4	*bb;
	int			col;
	int			row;

	aa = (t_matrix4 *) &a;
	bb = (t_matrix4 *) &b;
	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
		{
			(*res)[row][col] = a[row][0] * b[0][col] + a[row][1] * b[1][col]
				+ a[row][2] * b[2][col] + a[row][3] * b[3][col];
			row++;
		}
		col++;
	}
}
