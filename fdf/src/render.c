/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:13:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/15 19:55:35 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_image(t_render *r, t_win *win, int w, int h)
{
	r->img = (t_img *)malloc(sizeof(t_img));
	r->img->win = *win;
	r->img->ptr = mlx_new_image(win->mlx, w, h);
	if (!r->img->ptr)
		exit(EXIT_FAILURE);
	r->img->addr = mlx_get_data_addr(r->img->ptr, &(r->img->bpp),
			&(r->img->size_line), &(r->img->endian));
	r->img->w = w;
	r->img->h = h;
}

t_cam	*set_camera(void )
{
	t_cam	*cam;

	cam = (t_cam *) malloc(sizeof(t_cam));
	(cam->model).pos_mod = (t_vec3){0, -5, -6};
	(cam->model).ang_x = 0;
	(cam->model).ang_y = 0;
	(cam->model).ang_z = M_PI_2 / 3;
	set_transform_model(cam);
	(cam->view).pos_cam = (t_vec3){1, 1, 1};
	(cam->view).target = (t_vec3){0, 0, 0};
	(cam->view).up = (t_vec3){0, 1, 0};
	set_transform_view(cam);
	(cam->proj).type = PROJEC_SYMMETRIC;
	(cam->proj).max = (t_vec3){1, 1, 1};
	(cam->proj).min = (t_vec3){-1, -1, -1};
	set_transform_proj(cam);
	set_transform(cam);
	return (cam);
}

void	set_map(char *path, t_map **map)
{
	char	*file;
	char	**lines;

	file = ft_getfile(path);
	if (!file)
		exit(EXIT_FAILURE);
	lines = ft_split(file, '\n');
	free(file);
	*map = ft_fillmap(lines);
	free(lines);
}

t_render	*set_render(t_win *win, char *file)
{
	t_render	*new;

	new = (t_render *)malloc(sizeof(t_render));
	if (!new)
		exit(EXIT_FAILURE);
	ft_image(new, win, DEFAULT_IMGSIZX, DEFAULT_IMGSIZY);
	new->cam = set_camera();
	set_map(file, &(new->map));
	return (new);
}
