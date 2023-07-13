/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:28:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/13 19:38:15 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_line(t_render *r, t_point p0, t_point p1)
{
	t_line	l;

	p0.r = ft_mulm4v(r->cam->trasform, p0.r);
	p1.r = ft_mulm4v(r->cam->trasform, p1.r);
	l.dx = abs((int)p1.r.x - (int)p0.r.x);
	l.dy = abs((int)p1.r.y - (int)p0.r.y);
	l.dz = abs((int)p1.r.z - (int)p0.r.z);
	l.sx = (p0.r.x < p1.r.x) - (p0.r.x >= p1.r.x);
	l.sy = (p0.r.y < p1.r.y) - (p0.r.y >= p1.r.y);
	l.sz = (p0.r.z < p1.r.z) - (p0.r.z >= p1.r.z);
	l.dm = MAX(MAX(l.dx, l.dy), l.dz);
	l.i = l.dm;
	l.x1 = l.dm / 2;
	l.y1 = l.dm / 2;
	l.z1 = l.dm / 2;
	l.x0 = (int) p0.r.x;
	l.y0 = (int) p0.r.y;
	l.z0 = (int) p0.r.z;
	l.c = p0.color;
	l.dc = ft_divv4f(ft_subv4(p1.color, p0.color), (float) l.i);
	ft_plot_line(r->img, l);
	return (EXIT_SUCCESS);
}

int	ft_plot_map(t_render *r)
{
	int		x;
	int		y;

	y = -1;
	printf("%d\n", r->cam->button_press);
	while (++y < r->map->nrow -1)
	{
		x = -1;
		while (++x < r->map->ncol -1)
		{
			set_line(r, r->map->p[y * r->map->ncol + x],
				r->map->p[(y + 1) * r->map->ncol + x]);
			set_line(r, r->map->p[y * r->map->ncol + x],
				r->map->p[y * r->map->ncol + x + 1]);
		}
		set_line(r, r->map->p[y * r->map->ncol + x],
			r->map->p[(y + 1) * r->map->ncol + x]);
	}
	x = -1;
	while (++x < r->map->ncol -1)
		set_line(r, r->map->p[y * r->map->ncol + x],
			r->map->p[y * r->map->ncol + x + 1]);
	mlx_put_image_to_window(r->img->win.mlx, r->img->win.win,
		r->img->ptr, 0, 0);
	printf("ok\n");
	return (EXIT_SUCCESS);
}
