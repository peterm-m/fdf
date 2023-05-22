/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:15:20 by pedro             #+#    #+#             */
/*   Updated: 2023/05/22 15:59:19 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef float	t_matrix[3][3];

float	ft_dot_product(t_vec3 a, t_vec3 b);
t_vec3	ft_vector_product(t_vec3 *a, t_vec3 *b);
t_vec3	ft_normalize(t_vec3 a);
t_vec3	ft_bymat(t_vec3 *a, t_matrix mat);
t_vec3	ft_traslation(t_vec3 v, t_vec3 traslation);
t_vec3	ft_scaling(t_vec3 v, t_vec3 factors);
t_vec3	ft_byscalar(t_vec3 v, float a);
void	ft_matmul(t_matrix res, t_matrix a, t_matrix b);

void	print_vec3(t_vec3 v);
void	print_matrix(t_matrix m);
#endif