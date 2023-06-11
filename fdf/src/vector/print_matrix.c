/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:42:11 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 15:49:46 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_matrix2(t_matrix2 m)
{
	ft_printf("%f %f %f \n", m[0][0], m[0][1]);
	ft_printf("%f %f %f \n", m[1][0], m[1][1]);
}

void	print_matrix3(t_matrix3 m)
{
	ft_printf("%f %f %f \n", m[0][0], m[0][1], m[0][2]);
	ft_printf("%f %f %f \n", m[1][0], m[1][1], m[1][2]);
	ft_printf("%f %f %f \n", m[2][0], m[2][1], m[2][2]);
}

void	print_matrix4(t_matrix4 m)
{
	ft_printf("%f %f %f %f\n", m[0][0], m[0][1], m[0][2], m[0][3]);
	ft_printf("%f %f %f %f\n", m[1][0], m[1][1], m[1][2], m[1][3]);
	ft_printf("%f %f %f %f\n", m[2][0], m[2][1], m[2][2], m[2][3]);
	ft_printf("%f %f %f %f\n", m[3][0], m[3][1], m[3][2], m[3][3]);
}
