/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:15:20 by pedro             #+#    #+#             */
/*   Updated: 2023/06/24 20:35:46 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec2 {
	float	x;
	float	y;
}	t_vec2;

typedef float	t_matrix2[2][2];

void	ft_setrow2(t_matrix2 *mat, t_vec2 data, int row);
void	ft_setcol2(t_matrix2 *mat, t_vec2 data, int row);
t_vec2	ft_getrow2(t_matrix2 *mat, int row);
t_vec2	ft_getcol2(t_matrix2 *mat, int row);
void	ft_matmul2(t_matrix2 res, t_matrix2 a, t_matrix2 b);

void	print_matrix2(t_matrix2 m);

t_vec2	ft_bymat2(t_vec2 *a, t_matrix2 mat);
float	ft_dot_product2(t_vec2 a, t_vec2 b);
t_vec2	ft_normalize2(t_vec2 a);
t_vec2	ft_byscalar2(t_vec2 v, float a);
t_vec2	ft_minus2(t_vec2 v, t_vec2 traslation);
t_vec2	ft_scaling2(t_vec2 v, t_vec2 factors);

void	print_vec2(t_vec2 v);

typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef float	t_matrix3[3][3];

void	ft_setrow3(t_matrix3 *mat, t_vec3 data, int row);
void	ft_setcol3(t_matrix3 *mat, t_vec3 data, int row);
t_vec3	ft_getrow3(t_matrix3 *mat, int row);
t_vec3	ft_getcol3(t_matrix3 *mat, int row);
void	ft_matmul3(t_matrix3 res, t_matrix3 a, t_matrix3 b);

void	print_matrix3(t_matrix3 m);

t_vec3	ft_bymat3(t_vec3 *a, t_matrix3 mat);
float	ft_dot_product3(t_vec3 a, t_vec3 b);
t_vec3	ft_vector_product3(t_vec3 *a, t_vec3 *b);
t_vec3	ft_normalize3(t_vec3 a);
t_vec3	ft_byscalar3(t_vec3 v, float a);
t_vec3	ft_minus3(t_vec3 v, t_vec3 traslation);
t_vec3	ft_scaling3(t_vec3 v, t_vec3 factors);

void	print_vec3(t_vec3 v);

typedef struct s_vec4 {
	float	x;
	float	y;
	float	z;
	float	w;
}	t_vec4;

typedef float	t_matrix4[4][4];

void	ft_setrow4(t_matrix4 *mat, t_vec4 data, int row);
void	ft_setcol4(t_matrix4 *mat, t_vec4 data, int row);
t_vec4	ft_getrow4(t_matrix4 *mat, int row);
t_vec4	ft_getcol4(t_matrix4 *mat, int row);
void	ft_matmul4(t_matrix4 *res, t_matrix4 a, t_matrix4 b);

void	print_matrix4(t_matrix4 m);

float	ft_dot_product4(t_vec4 a, t_vec4 b);
t_vec4	ft_normalize4(t_vec4 a);
t_vec4	ft_bymat4(t_vec4 *a, t_matrix4 mat);
t_vec4	ft_byscalar4(t_vec4 v, float a);
t_vec4	ft_minus4(t_vec4 v, t_vec4 traslation);
t_vec4	ft_scaling4(t_vec4 v, t_vec4 factors);

void	print_vec4(t_vec4 v);
#endif