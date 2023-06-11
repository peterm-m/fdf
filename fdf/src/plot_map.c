/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:28:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/11 15:45:05 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_img(t_img *img, t_cam *cam, t_point p0, t_point p1)
{
//	t_vec4	v0;
//	t_vec4	v1;
//	t_pixel	pix0;
//	t_pixel	pix1;
//
//	v0 = (t_vec4){p0.r.x, p0.r.y, p0.r.z, 1};
//	ft_bymat4(&v0, cam->trasform);
//	v1 = (t_vec4){p1.r.x, p1.r.y, p1.r.z, 1};
//	ft_bymat4(&v1, cam->trasform);
//	if (v1.w == 0 || v0.w == 0)
//	{
//		v1.w = 1;
//		v0.w = 1;
//	}
//	p1.r = (t_vec3){v1.x / v1.w, v1.y / v1.w, v1.z / v1.w};
//	p0.r = (t_vec3){v0.x / v0.w, v0.y / v0.w, v0.z / v0.w};/*#CONTINUAR#*/
//	pix0.r = (t_ivec2){(int)(v0.x) + DEFAULT_IMGSIZX / 2,
//		(int)(v0.y / v0.w) + DEFAULT_IMGSIZY / 2};
//	pix0.color = p0.color;
//	pix1.r = (t_ivec2){(int )(v1.x) + DEFAULT_IMGSIZX / 2,
//		(int )(v1.y) + DEFAULT_IMGSIZY / 2};
//	pix1.color = p1.color;
//	ft_plot_line(img, pix0, pix1);
}

int	ft_plot_map(t_render *r)
{
//	int		x;
//	int		y;
//
//	ft_bzero((void *)(r->img->addr), r->img->h * r->img->size_line
//		+ r->img->w * (r->img->bpp / 8));
//	y = -1;
//	while (++y < r->map->nrow -1)
//	{
//		x = -1;
//		while (++x < r->map->ncol -1)
//		{
//			to_img(r->img, r->cam, point(r->map, x, y),
//				point(r->map, x, y + 1));
//			to_img(r->img, r->cam, point(r->map, x, y),
//				point(r->map, x + 1, y));
//		}
//		to_img(r->img, r->cam, point(r->map, x, y), point(r->map, x, y + 1));
//	}
//	x = -1;
//	while (++x < r->map->ncol -1)
//		to_img(r->img, r->cam, point(r->map, x, y), point(r->map, x + 1, y));
////	ft_plot_axis(r->img, r->cam);
//	mlx_put_image_to_window(r->img->win.mlx, r->img->win.win,
//		r->img->ptr, 0, 0);
//	return (EXIT_SUCCESS);
}
