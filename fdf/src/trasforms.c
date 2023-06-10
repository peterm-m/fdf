/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasforms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 18:32:20 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/10 17:43:45 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vec4	ft_tgetcol(t_trasform *mat, int col)
{
	return ((t_vec4){
		(*mat)[0][col],
	(*mat)[1][col],
	(*mat)[2][col],
	(*mat)[3][col]});
}

t_vec4	ft_tgetrow(t_trasform *mat, int row)
{
	return ((t_vec4){
		(*mat)[row][0],
	(*mat)[row][1],
	(*mat)[row][2],
	(*mat)[row][3]});
}

void	ft_tsetcol(t_trasform *mat, t_vec4 data, int col)
{
	(*mat)[0][col] = data.x;
	(*mat)[1][col] = data.y;
	(*mat)[2][col] = data.z;
	(*mat)[3][col] = data.w;
}

void	ft_tsetrow(t_trasform *mat, t_vec4 data, int row)
{
	(*mat)[row][0] = data.x;
	(*mat)[row][1] = data.y;
	(*mat)[row][2] = data.z;
	(*mat)[row][3] = data.w;
}

void	ft_tproduct(t_trasform *res, t_trasform *a, t_trasform *b)
{
	(*res)[0][0] = ft_tdot_product(ft_tgetrow(a, 0), ft_tgetcol(b, 0));
	(*res)[0][1] = ft_tdot_product(ft_tgetrow(a, 0), ft_tgetcol(b, 1));
	(*res)[0][2] = ft_tdot_product(ft_tgetrow(a, 0), ft_tgetcol(b, 2));
	(*res)[0][3] = ft_tdot_product(ft_tgetrow(a, 0), ft_tgetcol(b, 3));
	(*res)[1][0] = ft_tdot_product(ft_tgetrow(a, 1), ft_tgetcol(b, 0));
	(*res)[1][1] = ft_tdot_product(ft_tgetrow(a, 1), ft_tgetcol(b, 1));
	(*res)[1][2] = ft_tdot_product(ft_tgetrow(a, 1), ft_tgetcol(b, 2));
	(*res)[1][3] = ft_tdot_product(ft_tgetrow(a, 1), ft_tgetcol(b, 3));
	(*res)[2][0] = ft_tdot_product(ft_tgetrow(a, 2), ft_tgetcol(b, 0));
	(*res)[2][1] = ft_tdot_product(ft_tgetrow(a, 2), ft_tgetcol(b, 1));
	(*res)[2][2] = ft_tdot_product(ft_tgetrow(a, 2), ft_tgetcol(b, 2));
	(*res)[2][3] = ft_tdot_product(ft_tgetrow(a, 2), ft_tgetcol(b, 3));
	(*res)[3][0] = ft_tdot_product(ft_tgetrow(a, 3), ft_tgetcol(b, 0));
	(*res)[3][1] = ft_tdot_product(ft_tgetrow(a, 3), ft_tgetcol(b, 1));
	(*res)[3][2] = ft_tdot_product(ft_tgetrow(a, 3), ft_tgetcol(b, 2));
	(*res)[3][3] = ft_tdot_product(ft_tgetrow(a, 3), ft_tgetcol(b, 3));
}
