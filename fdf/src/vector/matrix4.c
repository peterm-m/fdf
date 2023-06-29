/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:20 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/29 20:54:39 by pedromar         ###   ########.fr       */
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

	aa = (t_matrix4 *) &a;
	bb = (t_matrix4 *) &b;
	(*res)[0][0] = ft_dot_product4(ft_getrow4(aa, 0), ft_getcol4(bb, 0));
	(*res)[0][1] = ft_dot_product4(ft_getrow4(aa, 0), ft_getcol4(bb, 1));
	(*res)[0][2] = ft_dot_product4(ft_getrow4(aa, 0), ft_getcol4(bb, 2));
	(*res)[0][3] = ft_dot_product4(ft_getrow4(aa, 0), ft_getcol4(bb, 3));
	(*res)[1][0] = ft_dot_product4(ft_getrow4(aa, 1), ft_getcol4(bb, 0));
	(*res)[1][1] = ft_dot_product4(ft_getrow4(aa, 1), ft_getcol4(bb, 1));
	(*res)[1][2] = ft_dot_product4(ft_getrow4(aa, 1), ft_getcol4(bb, 2));
	(*res)[1][3] = ft_dot_product4(ft_getrow4(aa, 1), ft_getcol4(bb, 3));
	(*res)[2][0] = ft_dot_product4(ft_getrow4(aa, 2), ft_getcol4(bb, 0));
	(*res)[2][1] = ft_dot_product4(ft_getrow4(aa, 2), ft_getcol4(bb, 1));
	(*res)[2][2] = ft_dot_product4(ft_getrow4(aa, 2), ft_getcol4(bb, 2));
	(*res)[2][3] = ft_dot_product4(ft_getrow4(aa, 2), ft_getcol4(bb, 3));
	(*res)[3][0] = ft_dot_product4(ft_getrow4(aa, 3), ft_getcol4(bb, 0));
	(*res)[3][1] = ft_dot_product4(ft_getrow4(aa, 3), ft_getcol4(bb, 1));
	(*res)[3][2] = ft_dot_product4(ft_getrow4(aa, 3), ft_getcol4(bb, 2));
	(*res)[3][3] = ft_dot_product4(ft_getrow4(aa, 3), ft_getcol4(bb, 3));
}
