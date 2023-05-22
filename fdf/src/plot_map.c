/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:28:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/22 15:59:13 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_img(t_img *img, t_cam *cam, t_point p0, t_point p1)
{
	t_vec3	v0;
	t_vec3	v1;
	t_pixel	pix0;
	t_pixel	pix1;

	v0 = ft_traslation(p0.r, cam->cam_pos);
	v0 = ft_bymat(&v0, cam->look);
	pix0.r = (t_ivec2){(int)v0.x + cam->offx + DEFAULT_IMGSIZX / 2,
		(int)v0.y + cam->offy + DEFAULT_IMGSIZY / 2};
	pix0.color = p0.color;
	v1 = ft_traslation(p1.r, cam->cam_pos);
	v1 = ft_bymat(&v1, cam->look);
	pix1.r = (t_ivec2){(int )v1.x + cam->offx + DEFAULT_IMGSIZX / 2,
		(int )v1.y + cam->offy + DEFAULT_IMGSIZY / 2};
	pix1.color = p1.color;
	ft_plot_line(img, pix0, pix1);
}

int	ft_plot_map(t_render *r)
{
	int		x;
	int		y;

	ft_bzero((void *)(r->img->addr), r->img->h * r->img->size_line
		+ r->img->w * (r->img->bpp / 8));
	y = -1;
	while (++y < r->map->nrow -1)
	{
		x = -1;
		while (++x < r->map->ncol -1)
		{
			to_img(r->img, r->cam, point(r->map, x, y),
				point(r->map, x, y + 1));
			to_img(r->img, r->cam, point(r->map, x, y),
				point(r->map, x + 1, y));
		}
		to_img(r->img, r->cam, point(r->map, x, y), point(r->map, x, y + 1));
	}
	x = -1;
	while (++x < r->map->ncol -1)
		to_img(r->img, r->cam, point(r->map, x, y), point(r->map, x + 1, y));
	ft_plot_axis(r->img, r->cam);
	mlx_put_image_to_window(r->img->win.mlx, r->img->win.win,
		r->img->ptr, 0, 0);
	return (EXIT_SUCCESS);
}
