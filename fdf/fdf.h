/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:39:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/17 19:34:38 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"

# include "controls.h"
# include "mlxcolor.h"

# include <math.h>

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

/*
* mlx struc
*/
typedef struct s_win {
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_win;

/*
* mathematical structures
*/
typedef struct s_ivec2 {
	int	x;
	int	y;
}	t_ivec2;

typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef float	t_matrix[3][3];

/*
* graphic structures
*/

typedef struct s_img {
	t_win	win;
	void	*ptr;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	int		w;
	int		h;
}	t_img;

typedef struct s_map {
	int	ncol;
	int	nrow;
	int	*z;
	int	*color;
}	t_map;

typedef struct s_cam {
	t_vec3		t;
	float		a;
	float		b;
	float		c;
	t_matrix	rot;
	float		focal;
	float		scale;
	float		sh;
	float		offx;
	float		offy;
	t_matrix	affin;
	t_matrix	look;
}	t_cam;

typedef struct s_render {
	t_img	*img;
	t_map	*map;
	t_cam	*cam;
}	t_render;

typedef struct s_pixel {
	t_ivec2	r;
	int		color;
}	t_pixel;

typedef struct s_point {
	t_vec3	r;
	int		color;
}	t_point;

/*
* mlx utils
*/
# define DEFAULT_WINX 512
# define DEFAULT_WINY 512
# define DEFAULT_IMGSIZX DEFAULT_WINX
# define DEFAULT_IMGSIZY DEFAULT_WINY

int		ft_r_color(int color);
int		ft_g_color(int color);
int		ft_b_color(int color);
int		ft_a_color(int color);
int		ft_color_rgba(int a, int r, int g, int b);

t_win	ft_program(int h, int w, char *str);
t_img	*ft_image(t_win win, int w, int h);
int		ft_end(t_win *win);

/*
* vetorial utils
*/
float	ft_dot_product(t_vec3 a, t_vec3 b);
t_vec3	ft_vector_product(t_vec3 *a, t_vec3 *b);
t_vec3	ft_normalize(t_vec3 a);
t_vec3	ft_bymat(t_vec3 *a, t_matrix mat);
t_vec3	ft_traslation(t_vec3 v, t_vec3 traslation);
t_vec3	ft_scaling(t_vec3 v, t_vec3 factors);
t_vec3	ft_byscalar(t_vec3 v, float a);
void	ft_matmul(t_matrix res, t_matrix a, t_matrix b);

/*
* Maps
*/
void	ft_parser(char *path, t_map **map);
t_point	ft_point(t_map *map, int x, int y);

/*
* Camera
*/
// defeault position

void	set_camrot(t_cam *cam);
void	set_camaffin(t_cam *cam);
void	set_camlook(t_cam *cam);
t_cam	*ft_newcam(void );
void	ft_rotation(t_cam *cam, t_vec3 r);
void	ft_scala(t_cam *cam);

/*
* Primitive plots
*/
void	ft_put_pixel(t_img img, int x, int y, int color);
void	ft_plot_line(t_img *img, t_pixel r0, t_pixel r1);
void	ft_plot_circle(t_img *img, int color, int rad, t_ivec2 r0);

/*
*  plot map
*/
void	projection(t_img *img, t_matrix look, t_vec3 t, t_point p0, t_point p1);
int		ft_plot_map(t_render	*render);

/////////////// DEBUG ////////////////////////
void	print_win(char *name, t_win *w);

void	print_vec3(char *name, t_vec3 v);
void	print_ivec2(char *name, t_ivec2 v);
void	print_matrix(char *name, t_matrix m);

void	print_map(char *name, t_map map);
void	print_cam(char *name, t_cam cam);
void	print_pix(char *name, t_pixel p);
void	print_line(char *name, t_pixel p0, t_pixel p1);
void	ft_axis(t_img *img, t_map *map, t_cam *cam);
void	info_render(t_render *r);
#endif
