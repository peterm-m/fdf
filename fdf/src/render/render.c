/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:13:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/30 21:11:23 by pedromar         ###   ########.fr       */
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

t_cam	*new_camera(void )
{
	t_cam	*cam;

	cam = (t_cam *) malloc(sizeof(t_cam));
	if (!cam)
		exit(EXIT_FAILURE);
	cam->model = (t_matrix4 *)new_matrix4();
	cam->proj = new_matrix4();
	cam->view = new_matrix4();
	cam->trasform = new_matrix4();
	if (!cam->proj || !cam->trasform || !cam->view || !cam->model)
		exit(EXIT_FAILURE);
	cam->proj_type = PROJECTION;
	cam->pos_view = (t_vec3){1, 1, 1};
	cam->rot_view = (t_vec3){0, 0, 0};
	cam->pos_model = (t_vec3){1, 1, 1};
	cam->rot_model = (t_vec3){0, 0, 0};
	cam->proj_max = (t_vec3){0, 0, 0};
	cam->proj_min = (t_vec3){0, 0, 0};
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
	new->cam = new_camera();
	set_map(file, &(new->map));
	return (new);
}
