/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:39:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/15 20:18:31 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"

# include <math.h>

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

/*
* mlx datas
*/
typedef struct s_win {
	void	*mlx;
	void	*win;
	int		w;
	int		h;
}	t_win;

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
	int	max_x;
	int	max_y;
	int	*arr_z;
	int	*arr_color;
}	t_map;

/*
* geometric data
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

/*     vectoril basis
*         +z          
*          |          
*          |          
*          |          
*          -------- +x
*           \         
*            \        
*             \ y+    
*/

typedef struct s_base3 {
	t_vec3	e1;
	t_vec3	e2;
	t_vec3	e3;
}	t_base3;

/*  Camera
* cam in e1 direction
*   e2 x screen
*   e3 y screen
*/

typedef struct s_cam {
	t_vec3	pos;
	t_base3	base;
}	t_cam;

typedef struct s_point {
	t_vec3	r;
	int		color;
}	t_point;

# define F_ESC 53

/*
* mlx utils
*/
# define DEFAULT_WINX 1920
# define DEFAULT_WINY 1080
# define DEFAULT_IMGSIZX DEFAULT_WINX
# define DEFAULT_IMGSIZY DEFAULT_WINY

t_win	ft_program(int h, int w, char *str);
t_img	ft_image(t_win win, int w, int h);
int		ft_end(t_win *win);

// vector utils
float	ft_dot_product(t_vec3 a, t_vec3 b);
t_vec3	ft_vector_product(t_vec3 *a, t_vec3 *b);
t_vec3	ft_normalize(t_vec3 a);
t_vec3	ft_matmul(t_vec3 *a, float **mat);
t_vec3	ft_sum(t_vec3 v, t_vec3 traslation);
t_vec3	ft_scaling(t_vec3 v, t_vec3 factors);
t_vec3	ft_byscalar(t_vec3 v, float a);
/*
* ARGB utils
*/
# define CL_RED 8
# define CL_GREEN 4
# define CL_BLUE 2
# define CL_ALPHA 1

# define CL_MASK_ALPHA 0xFF000000
# define CL_MASK_RED   0x00FF0000
# define CL_MASK_GREEN 0x0000FF00
# define CL_MASK_BLUE  0x000000FF

# define CL_POS_ALPHA 24
# define CL_POS_RED 16
# define CL_POS_GREEN 8
# define CL_POS_BLUE 0

int		ft_r_color(int color);
int		ft_g_color(int color);
int		ft_b_color(int color);
int		ft_a_color(int color);
int		ft_color_rgba(int a, int r, int g, int b);

/*
* Maps
*/
void	ft_parser(char *path, t_map **map);
t_point	ft_point(t_map *map, int x, int y);
/*
* Camera
*/
// defeault position
# define DEFAULT_CAM_XPOS 10
# define DEFAULT_CAM_YPOS 10
# define DEFAULT_CAM_ZPOS 10

# define DEFAULT_CAM_PHI 0.785398F
# define DEFAULT_CAM_THETA 0

t_cam	ft_newcam(void );
void	ft_rotation(t_cam *cam, t_vec3 rotation); // no

/*
* Primitive plots
*/
void	ft_put_pixel(t_img img, int x, int y, int color);
void	ft_plot_line(t_img *img, int color, t_ivec2 r0, t_ivec2 r1);
void	ft_plot_circle(t_img *img, int color, int rad, t_ivec2 r0);

/*
*  plot map
*/
void	ft_plot_map(t_img img, t_map *map, t_cam cam);
// zoom
// Clipping
// Positioning
// Projection

#endif
