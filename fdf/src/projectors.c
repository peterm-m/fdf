/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:41:03 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 15:42:23 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_cam *c)
{
	t_vec3	max;
	t_vec3	min;

	min = (c->proj).min;
	max = (c->proj).max;
	if (fabs(max.x - min.x) > 0.0001 && fabs(max.y - min.y) > 0.0001
		&& fabs(max.z - min.z) > 0.0001)
	{
		ft_setrow4(&(c->proj).proj, (t_vec4){2 * max.z / (max.x - min.x), 0,
			(max.x + min.x) / (max.x - min.x), 0}, 0);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 2 * max.z / (max.y - min.y),
			(max.y + min.y) / (max.y - min.y), 0}, 1);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 0, -1 * (max.z + min.z)
			/ (max.z - min.z), -2 * max.z * min.z / (max.z - min.z)}, 2);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 0, -1, 0}, 3);
	}
}

void	sym_projection(t_cam *c)
{
	t_vec3	max;
	t_vec3	min;

	min = (c->proj).min;
	max = (c->proj).max;
	if (fabs(max.x - min.x) > 0.0001 && fabs(max.y - min.y) > 0.0001
		&& fabs(max.z - min.z) > 0.0001)
	{
		ft_setrow4(&(c->proj).proj, (t_vec4){min.z / max.x, 0, 0,
			-1 * (max.x + min.x) / (max.x - min.x)}, 0);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, min.z / max.y, 0, 0}, 1);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 0, -1 * (max.z + min.z)
			/ (max.z - min.z), -2 * min.z * max.z / (max.z - min.z)}, 2);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 0, -1, 0}, 3);
	}
}

void	orthographic(t_cam *c)
{
	t_vec3	max;
	t_vec3	min;

	min = (c->proj).min;
	max = (c->proj).max;
	if (fabs(max.x - min.x) > 0.0001 && fabs(max.y - min.y) > 0.0001
		&& fabs(max.z - min.z) > 0.0001)
	{
		ft_setrow4(&(c->proj).proj, (t_vec4){2 / (max.x - min.x), 0, 0,
			-1 * (max.x + min.x) / (max.x - min.x)}, 0);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 2 / (max.y - min.y), 0,
			-1 * (max.y + min.y) / (max.y - min.y)}, 1);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 0, -2 / (max.z - min.z),
			-1 * (max.z + min.z) / (max.z - min.z)}, 2);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 0, 0, 1}, 3);
	}
}

void	sym_orthographic(t_cam *c)
{
	t_vec3	max;
	t_vec3	min;

	min = (c->proj).min;
	max = (c->proj).max;
	if (fabs(max.x - min.x) > 0.0001 && fabs(max.y - min.y) > 0.0001
		&& fabs(max.z - min.z) > 0.0001)
	{
		ft_setrow4(&(c->proj).proj, (t_vec4){1 / max.x, 0, 0, 0}, 0);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 1 / max.y, 0, 0}, 1);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 0, -2 / (max.z - min.z),
			-1 * (max.z + min.z) / (max.z - min.z)}, 2);
		ft_setrow4(&(c->proj).proj, (t_vec4){0, 0, 0, 1}, 3);
	}
}
