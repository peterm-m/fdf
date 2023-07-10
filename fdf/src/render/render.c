/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:13:17 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/10 20:01:37 by pedromar         ###   ########.fr       */
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
	cam->proj_type = ORTHO_SYMMETRIC ;
	cam->pos_view = ft_vec3(0.0f, 0.0f, 0.0f);
	cam->rot_view = ft_vec3(0.0f, 0.0f, 0.0f);
	cam->pos_model = ft_vec3(0.0f, 0.0f, 0.0f);
	cam->rot_model = ft_vec3(0.0f, 0.0f, 0.0f);
	cam->proj_max = ft_vec3(1.0f, 1.0f, 1.0f);
	cam->proj_min = ft_vec3(-1.0f, -1.0f, -1.0f);
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
