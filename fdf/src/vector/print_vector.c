/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_vector.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 13:42:11 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/30 20:22:22 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_vec2(t_vec2 m)
{
	printf("%f %f\n", m.x, m.y);
}

void	print_vec3(t_vec3 m)
{
	printf("%f %f %f \n", m.x, m.y, m.z);
}

void	print_vec4(t_vec4 m)
{
	printf("%f %f %f %f\n", m.x, m.y, m.z, m.w);
}
