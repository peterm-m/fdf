/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trasformations.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:43:14 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/07 18:48:56 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRASFORMATIONS_H
# define TRASFORMATIONS_H

# include "vector.h"

t_matrix4	translate(t_vec3 translation);
t_matrix4	inv_translate(t_matrix4 translation_m);

t_matrix4	scale(t_vec3 scale);
t_matrix4	invscale(t_matrix4 scale_m);

t_matrix4	rotater(float a, t_vec3 axis);
t_matrix4	rotatel(float a, t_vec3 axis);
t_matrix4	invrotate(t_matrix4 rotation_m);

t_matrix4	lookatr(t_vec3 target, t_vec3 updir, t_vec3 eye);
t_matrix4	lookatl(t_vec3 target, t_vec3 updir, t_vec3 eye);
t_matrix4	invlookat(t_matrix4 lookat_m);

t_matrix4	orthographicr(t_vec3 max, t_vec3 min);
t_matrix4	orthographicl(t_vec3 max, t_vec3 min);
t_matrix4	invorthographic(t_matrix4 ortho_m);

t_matrix4	perspectiver(float fov, float aspect, float near, float far);
t_matrix4	invperspectiver(t_matrix4 pers_m);
t_matrix4	perspectivel(float fov, float aspect, float near, float far);
t_matrix4	invperspectivel(t_matrix4 pers_m);

#endif