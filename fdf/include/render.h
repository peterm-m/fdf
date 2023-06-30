/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:49:59 by pedro             #+#    #+#             */
/*   Updated: 2023/06/30 20:00:04 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fdf.h"

typedef struct s_map {
	int	ncol;
	int	nrow;
	int	*z;
	int	*color;
}	t_map;

# define PROJECTION 0
# define ORTHOGRAPHIC 1
# define PROJEC_SYMMETRIC 2
# define ORTHO_SYMMETRIC 3

typedef struct s_proj {
	int			type;
	t_vec3		max;
	t_vec3		min;
	t_matrix4	proj;
}	t_proj;

typedef struct s_cam {
	t_vec3		pos_view;
	t_vec3		rot_view;
	t_matrix4	*view;
	t_vec3		pos_model;
	t_vec3		rot_model;
	t_matrix4	*model;
	int			proj_type;
	t_vec3		proj_max;
	t_vec3		proj_min;
	t_matrix4	*proj;
	t_matrix4	*trasform;
}	t_cam;

# define DEFAULT_WINX 1024
# define DEFAULT_WINY 1024
# define DEFAULT_IMGSIZX DEFAULT_WINX
# define DEFAULT_IMGSIZY DEFAULT_WINY

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

typedef struct s_render {
	t_img	*img;
	t_map	*map;
	t_cam	*cam;
}	t_render;

t_win		ft_program(int h, int w, char *str);
int			ft_end_program(t_render *r);

void		set_map(char *path, t_map **map);
t_map		*ft_newmap(int x, int y);
void		ft_mapline(char *line, t_map *map, int y);
t_map		*ft_fillmap(char **lines);
void		ft_print_map(t_map *m);

void		set_transform_model(t_cam *c);

void		set_transform_view(t_cam *c);

void		set_transform_proj(t_cam *c);
void		sym_projection(t_cam *c);
void		orthographic(t_cam *c);
void		sym_orthographic(t_cam *c);
void		projection(t_cam *c);

void		ft_image(t_render *r, t_win *win, int w, int h);

t_render	*set_render(t_win *win, char *file);
void		set_transform(t_cam *c);

#endif

/*#CONTINUE#*/
/*
*  Rationale:
*RENDER contains the set of elements to draw an image on the screen.These are: 
*   Sets of elements to be drawn, map.
*   An observer, cam.
*   Information to display on the screen
* MAP struct contains all the information of the fdf file.
* CAM version 2 contains the necessary information about the observer
* IMG contains the information of the
* map projected on the screen and the data to display it on the screen.
*/
