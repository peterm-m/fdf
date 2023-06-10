/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:49:59 by pedro             #+#    #+#             */
/*   Updated: 2023/06/10 19:51:29 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fdf.h"
//point struct contains the information of a value (x,y) map.
typedef struct s_point {
	t_vec3	r;
	int		color;
}	t_point;
// line struct
typedef struct s_line {
	t_point	p0;
	t_point	p1;
}	t_line;
/*
*  MAP struct contains all the information of the fdf file.
*/
typedef struct s_map {
	int	ncol;
	int	nrow;
	int	*z;
	int	*color;
}	t_map;
/*
* CAM contains the necessary information about the observer
* and the perspective from which the map is observed.
*/
typedef struct s_cam {
	t_vec3		cam_pos;
	t_vec3		t;
	float		a;
	float		b;
	float		c;
	float		focal;
	float		scale;
	float		sh;
	float		offx;
	float		offy;
	t_matrix	rot;
	t_matrix	affin;
	t_matrix	look;
}	t_cam;
/*
* CAM version 2 contains the necessary information about the observer
*/
typedef struct s_model {
	t_vec3		pos_mod;
	float		ang_z;
	float		ang_y;
	float		ang_x;
	t_trasform	model;
}	t_model;

typedef struct s_view {
	t_vec3		pos_cam;
	t_vec3		target;
	t_vec3		up;
	t_trasform	view;
}	t_view;

# define PROJECTION 0
# define ORTHOGRAPHIC 1
# define PROJEC_SYMMETRIC 2
# define ORTHO_SYMMETRIC 3

typedef struct s_proj
{
	int			type;
	t_vec3		max;
	t_vec3		min;
	t_trasform	proj;
}	t_proj;

typedef struct s_cam2 {
	t_model		model;
	t_view		view;
	t_proj		proj;
	t_trasform	trasform;
}	t_cam2;
/*
* IMG contains the information of the
* map projected on the screen and the data to display it on the screen.
*/
// ivec2 two-dimensional position of an image.
typedef struct s_ivec2 {
	int	x;
	int	y;
}	t_ivec2;
// sets position and color of the position of an image
typedef struct s_pixel {
	t_ivec2	r;
	int		color;
}	t_pixel;
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
/*
*RENDER contains the set of elements to draw an image on the screen.These are: 
*   Sets of elements to be drawn, map.
*   An observer, cam.
*   Information to display on the screen
*/
typedef struct s_render {
	t_img	*img;
	t_map	*map;
	t_cam2	*cam;
}	t_render;

/*
* Maps
*/
void	ft_parser(char *path, t_map **map);
t_point	point(t_map *map, int x, int y);
void	ft_print_map(t_map *m);
/*
* Camera
*/
t_cam	*ft_newcam(void );
t_cam2	*ft_newcam2(void );
void	set_transform_model(t_cam2 *c);
void	set_transform_view(t_cam2 *c);
void	set_transform_proj(t_cam2 *c);
void	set_transform(t_cam2 *c);
void	sym_projection(t_cam2 *c);
void	orthographic(t_cam2 *c);
void	sym_orthographic(t_cam2 *c);
void	projection(t_cam2 *c);
void	set_cam_rot(t_cam *cam);
void	set_cam_affin(t_cam *cam);
void	set_cam_look(t_cam *cam);
void	print_cam(t_cam cam);
/*
* Image
*/
t_img	*ft_image(t_win win, int w, int h);

#endif