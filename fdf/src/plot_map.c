/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:28:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/07/10 21:20:41 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	set_line(t_render *r, t_point p0, t_point p1)
{
	t_line	l;

	p0.r = ft_mulm4v(r->cam->trasform, p0.r);
	p1.r = ft_mulm4v(r->cam->trasform, p1.r);
	printf("r0\n");
	printv4(p0.r);
	printf("r1\n");
	printv4(p1.r);
	l.x0 = (int) p0.r.x;
	l.y0 = (int) p0.r.y;
	l.z0 = (int) p0.r.z;
	l.x1 = (int) p1.r.x;
	l.y1 = (int) p1.r.y;
	l.z1 = (int) p1.r.z;
	l.c0 = p0.color;
	l.c1 = p1.color;
	ft_plot_line(r->img, l.x0, l.y0, l.z0, l.x1, l.y1, l.z1);
	return (EXIT_SUCCESS);
}

int	ft_plot_map(t_render *r)
{
	int		x;
	int		y;

	y = -1;
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
	return (EXIT_SUCCESS);
}

