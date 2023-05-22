/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:49:59 by pedro             #+#    #+#             */
/*   Updated: 2023/05/22 16:48:37 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fdf.h"
/*
*  MAP struct contains all the information of the fdf file.
*/
typedef struct s_map {
	int	ncol;
	int	nrow;
	int	*z;
	int	*color;
}	t_map;
//point struct contains the information of a value (x,y) of the map.
typedef struct s_point {
	t_vec3	r;
	int		color;
}	t_point;
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
* IMG contains the information of the
* map projected on the screen and the data to display it on the screen.
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
/*
*RENDER contains the set of elements to draw an image on the screen.These are: 
*   Sets of elements to be drawn, map.
*   An observer, cam.
*   Information to display on the screen
*/
typedef struct s_render {
	t_img	*img;
	t_map	*map;
	t_cam	*cam;
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
void	set_cam_rot(t_cam *cam);
void	set_cam_affin(t_cam *cam);
void	set_cam_look(t_cam *cam);
void	print_cam( t_cam cam);
/*
* Image
*/
t_img	*ft_image(t_win win, int w, int h);

#endif