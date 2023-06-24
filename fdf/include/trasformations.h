/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasformations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:43:14 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/24 20:33:52 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASFORMATIONS_H
# define TRASFORMATIONS_H

# include "vector.h"

void	traslation(t_vec3 *t, t_matrix4 *mat);

void	scale(t_vec3 *s, t_matrix4 *mat);

void	axis_rotation(float angle, t_vec3 *axis, t_matrix4 *mat);
void	rotationx(float angle, t_matrix4 *mat);
void	rotationy(float angle, t_matrix4 *mat);
void	rotationz(float angle, t_matrix4 *mat);
void	angle_to_axes(t_vec3 *a, t_matrix4 *mat);

void	look_at(t_vec3 *eye, t_vec3 *target, t_vec3 *up_dir, t_matrix4 *mat);
void	look_at_axes1(t_vec3 *pos, t_vec3 *target, t_matrix4 *mat);
t_vec3	lookat_angles(t_matrix4 *mat);

#endif