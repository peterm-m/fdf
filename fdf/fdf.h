/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 12:39:01 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/12 20:27:52 by pedromar         ###   ########.fr       */
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
* Basic
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
}				t_img;

/*
*	BitMap O-RGB
*/
# define CL_RED 8
# define CL_GREEN 4
# define CL_BLUE 2
# define CL_OO 1

# define CL_MASK_OO    0xFF000000
# define CL_MASK_RED   0x00FF0000
# define CL_MASK_GREEN 0x0000FF00
# define CL_MASK_BLUE  0x000000FF

# define CL_POS_OO 24
# define CL_POS_RED 16
# define CL_POS_GREEN 8
# define CL_POS_BLUE 0

# define F_ESC 53

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

typedef struct s_plane
{
	t_vec3	n;
	t_vec3	p0;
}	t_plane;

typedef struct s_map {
	int	max_x;
	int	max_y;
	int	*arr_z;
	int	*arr_color;
}	t_map;

typedef struct s_spectator {
	t_vec3	pos;
	t_plane	screen;
	float	scaling;
	float	theta;
}	t_spectator;

t_img	ft_image(int w, int h, t_win win);
int		ft_color_rgb(int color, char type);
int		ft_regb_color(int o, int r, int g, int b);
void	ft_put_pixel(t_img img, int x, int y, int color);

t_img	ft_image(int w, int h, t_win win);
int		ft_color_rgb(int color, char type);
void	ft_put_pixel(t_img img, int x, int y, int color);
int		ft_rgb_color(int o, int r, int g, int b);
void	ft_put_pixel(t_img img, int x, int y, int color);

void	ft_plot_line(t_img *img, int color, t_ivec2 r0, t_ivec2 r1);
void	plotLine3d(t_img *img, t_ivec2 r0, int color0, t_ivec2 r1, int color1);
t_map	*ft_parser(char *path);
size_t	ft_wc_bytes(char *path);
char	*ft_getfile(char *path);
void	ft_mapline(char *line, t_map *map, int x);
t_map	*ft_newmap(int x, int y);
t_map	*ft_fillmap(char **lines);

// trasformation



#endif
