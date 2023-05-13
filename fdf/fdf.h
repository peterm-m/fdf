/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:39:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/13 17:13:43 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

/*
* mlx utils
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
*	Geometry primitives
*/
typedef struct s_ivec2 {
	int	x;
	int	y;
}	t_ivec2;

typedef struct s_ivec3 {
	int	x;
	int	y;
	int	z;
}	t_ivec3;

typedef struct s_vec2 {
	float	x;
	float	y;
}	t_vec2;

typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct s_plane {
	t_vec3	n;
	t_vec3	p0;
}	t_plane;

typedef struct s_spectator {
	t_vec3	pos;
	t_plane	screen;
	float	scaling;
	float	theta;
}	t_spectator;

/*
* BitMap O-RGB
*/
# define CL_RED 8
# define CL_GREEN 4
# define CL_BLUE 2
# define CL_ALPHA 1

# define CL_MASK_ALPHA    0xFF000000
# define CL_MASK_RED   0x00FF0000
# define CL_MASK_GREEN 0x0000FF00
# define CL_MASK_BLUE  0x000000FF

# define CL_POS_ALPHA 24
# define CL_POS_RED 16
# define CL_POS_GREEN 8
# define CL_POS_BLUE 0

# define F_ESC 53

# define DEFAULT_WINSIZX 1920
# define DEFAULT_WINSIZY 1080
# define DEFAULT_IMGSIZX DEFAULT_WINSIZX
# define DEFAULT_IMGSIZY DEFAULT_WINSIZY

// mlx util
t_win	ft_program(int h, int w, char *str);
t_img	ft_image(t_win win, int w, int h);
int		ft_end(t_win *win);

// color utils
int		ft_r_color(int color);
int		ft_g_color(int color);
int		ft_b_color(int color);
int		ft_a_color(int color);
int		ft_color_rgba(int a, int r, int g, int b);

// geometric primitives
void	ft_put_pixel(t_img img, int x, int y, int color);
void	ft_plot_line(t_img *img, int color, t_ivec2 r0, t_ivec2 r1);
void	ft_plot_circle(t_img *img, int color, int rad, t_ivec2 r0);

// maps
t_map	*ft_parser(char *path);
void	ft_mapline(char *line, t_map *map, int x);
t_map	*ft_newmap(int x, int y);
t_map	*ft_fillmap(char **lines);

//Transformations 3d
void	tr_traslation3(t_vec3 *v, t_vec3 traslation);
void	tr_scaling3(t_vec3 *a, t_vec3 scaling_factor);
void	tr_rotation3(t_vec3 *a, t_vec3 rotation);

//Transformations 2d
void	tr_traslation2(void *a, t_vec2 traslation);
void	tr_scaling2(void *a, t_vec2 factors);
void	tr_rotation2(void *a, t_vec2 rotation);

// viwing
// windowing
// zoom
// Clipping
// Positioning
// Projection
