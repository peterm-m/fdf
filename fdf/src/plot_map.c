/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:28:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/06/12 20:09:39 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_imgage(t_render *r, t_point p0, t_point p1)
{
	t_line	l;

	l.p0.x = (int) p0.r.x;
	l.p0.y = (int) p0.r.y;
	l.p0.color = (int) p1.color;
	l.p1.x = (int) p1.r.x;
	l.p1.y = (int) p1.r.y;
	l.p1.color = (int) p1.color;
	l.dx = abs(l.p1.x - l.p0.x);
	l.dy = abs(l.p1.y - l.p0.y);
	l.sx = -1;
	if (l.p0.x < l.p1.x)
		l.sx = 1;
	l.sy = -1;
	if (l.p0.y < l.p1.y)
		l.sx = 1;
	l.err = l.dx + l.dy;
	ft_plot_line(r->img, &l);
}

t_point	to_windows(t_render *r, int x, int y)
{
	t_point	p;
	t_vec4	v;

	v = ft_bymat4((t_vec4 *){x, y,
			r->map->z[y * r->map->ncol + x], 0},
			r->cam->trasform);
	if (v.w == 0)
		v.w = 0.01;
	p.r = (t_vec3){r->img->w / 2 * v.x / v.w + r->img->w / 2,
		r->img->h / 2 * v.y / v.w + r->img->h / 2,
		(r->cam->proj.min.z - r->cam->proj.max.z) / 2 * v.z / v.w
		+ (r->cam->proj.min.z - r->cam->proj.max.z) / 2};
	p.color = r->map->color[y * r->map->ncol + x];
	return (p);
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
			to_imgage(r, to_windows(r, x, y),
				to_windows(r, x, y + 1));
			to_imgage(r, to_windows(r, x, y),
				to_windows(r, x + 1, y));
		}
		to_imgage(r, to_windows(r, x, y), to_windows(r, x, y + 1));
	}
	x = -1;
	while (++x < r->map->ncol -1)
		to_imgage(r, to_windows(r, x, y), to_windows(r, x + 1, y));
	mlx_put_image_to_window(r->img->win.mlx, r->img->win.win,
		r->img->ptr, 0, 0);
	return (EXIT_SUCCESS);
}
