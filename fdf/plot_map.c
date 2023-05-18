/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedromar <pedromar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:28:29 by pedromar          #+#    #+#             */
/*   Updated: 2023/05/15 20:20:50 by pedromar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_img *img, t_matrix look, t_vec3 t, t_point p0, t_point p1)
{
	t_vec3	v0;
	t_vec3	v1;
	t_pixel	pix0;
	t_pixel	pix1;
	
	v0 = ft_traslation(p0.r, t);
	v0 = ft_bymat(&v0, look);
	pix0.r = (t_ivec2){(int)v0.x +DEFAULT_WINX/2, (int)v0.y+DEFAULT_WINY/2};
	pix0.color = p0.color;
	v1 = ft_traslation(p1.r, t);
	v1 = ft_bymat(&v1, look);
	pix1.r = (t_ivec2){(int)v1.x +DEFAULT_WINX/2, (int)v1.y +DEFAULT_WINY/2};
	pix1.color = p1.color;
	ft_plot_line(img, pix0, pix1);
}

int	ft_plot_map(t_render *r)
{
	int		x;
	int		y;

	y = 0;
	while (y < r->map->nrow -1)
	{
		x = 0;
		while (x < r->map->ncol -1)
		{
			projection(r->img, r->cam->look, r->cam->t, ft_point(r->map, x, y), ft_point(r->map, x, y + 1));
			projection(r->img, r->cam->look, r->cam->t, ft_point(r->map, x, y), ft_point(r->map, x + 1, y));
			x++;
		}
		projection(r->img, r->cam->look, r->cam->t, ft_point(r->map, x, y), ft_point(r->map, x, y + 1));
		y++;
	}
	x = 0;
	while (x < r->map->ncol -1)
	{
		projection(r->img, r->cam->look, r->cam->t,ft_point(r->map, x, y), ft_point(r->map, x + 1, y));
		x++;
	}
	ft_axis(r->img, r->map, r->cam);
	mlx_put_image_to_window(r->img->win.mlx, r->img->win.win, r->img->ptr, 0, 0);
	return (EXIT_SUCCESS);
}
