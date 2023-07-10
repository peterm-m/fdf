/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:49:59 by pedro             #+#    #+#             */
/*   Updated: 2023/07/10 21:21:27 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "fdf.h"

# define PROJECTION 0
# define ORTHOGRAPHIC 1
# define PROJEC_SYMMETRIC 2
# define ORTHO_SYMMETRIC 3

# define DEFAULT_WINX 1024
# define DEFAULT_WINY 1024
# define DEFAULT_IMGSIZX DEFAULT_WINX
# define DEFAULT_IMGSIZY DEFAULT_WINY

typedef struct s_point {
	t_vec4	r;
	t_vec4	color;
}	t_point;

typedef struct s_map {
	int		ncol;
	int		nrow;
	t_point	*p;
}	t_map;

typedef struct s_cam {
	t_vec3		pos_view;
	t_vec3		rot_view;
	t_vec3		pos_model;
	t_vec3		rot_model;
	t_vec3		proj_max;
	t_vec3		proj_min;
	int			proj_type;
	t_matrix4	view;
	t_matrix4	model;
	t_matrix4	proj;
	t_matrix4	trasform;
}	t_cam;

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

t_render	*set_render(t_win *win, char *file);
void		set_transform(t_cam *c);
void		ft_put_pixel(t_img *img, int x, int y, int c);
void		ft_plot_line(t_img *img, int x0, int y0, int z0 , int x1, int y1, int z1);

#endif
